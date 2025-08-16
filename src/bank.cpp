#include "bank.h"
#include "currentAccount.h"
#include "savingAccount.h"
#include "utils.h"
#include <iostream>

Bank::Bank(UserManager *manager) { userManager = manager; }

AccountHolder *Bank::registerAccountHolder(const std::string &name,
                                           const std::string &email,
                                           const std::string &phone,
                                           const std::string &username,
                                           const std::string &password,
                                           int existingID)
{
    if (!isValidName(name))
    {
        std::cout << "Name must be string" << std::endl;
        return nullptr;
    }

    if (!isValidEmail(email))
    {
        std::cout << "Email must be valid" << std::endl;
        return nullptr;
    }

    if (!isValidPhone(phone))
    {
        std::cout << "Phone must be exactly 10 digits" << std::endl;
        return nullptr;
    }

    if (!isValidPassword(password))
    {
        std::cout << "Password must be min 7 characters" << std::endl;
        return nullptr;
    }
    int id;
    if (existingID != -1)
    {
        id = existingID;
    }
    else
    {
        id = rand() % 900000 + 100000;
    }

    User *existingUser = userManager->getUserByUsername(username);

    if (existingUser && existingUser->getRole() == Role::ACCOUNT_HOLDER)
    {
        std::cout << "Username already exists for Account Holder" << std::endl;
        return nullptr;
    }

    AccountHolderInfo info{id, name, Role::ACCOUNT_HOLDER, email, phone};
    AccountHolder *holder = new AccountHolder(info);
    if (!userManager->addUser(holder, username, password))
    {
        delete holder;
        return nullptr;
    }
    return holder;
}

Admin *Bank::registerAdmin(const std::string &name, const std::string &username, const std::string &password)
{
    if (!isValidName(name))
    {
        std::cout << "Name must be string" << std::endl;
        return nullptr;
    }

    if (!isValidPassword(password))
    {
        std::cout << "Password must be min 7 characters" << std::endl;
        return nullptr;
    }

    if (userManager->getUserByUsername(username))
    {
        std::cout << "Username already exists" << std::endl;
        return nullptr;
    }

    int id = rand() % 900000 + 100000;

    UserInfo info{id, name, Role::ADMIN};
    Admin *admin = new Admin(info);
    userManager->addUser(admin, username, password);
    return admin;
}

Account *Bank::createAccount(AccountHolder *holder, AccountType type)
{
    Account *account = nullptr;

    if (type == AccountType::CURRENT_ACCOUNT)
    {
        account = new CurrentAccount();
    }
    else
    {
        account = new SavingsAccount();
    }

    int accountNumberGenerator = rand() % 900000000 + 100000000;
    account->setAccountNumber(accountNumberGenerator);
    accounts.push_back(account);
    holder->addAccount(account);
    return account;
}

bool Bank::closeAccount(int accountNumber)
{
    for (int iteratorI = 0; iteratorI < accounts.size(); iteratorI++)
    {
        if (accounts[iteratorI]->getAccountNumber() == accountNumber)
        {
            for (User *user : userManager->getAllUsers())
            {
                if (user->getRole() == Role::ACCOUNT_HOLDER)
                {
                    AccountHolder *holder = static_cast<AccountHolder *>(user);
                    holder->deleteAccount(accountNumber);
                }
            }

            delete accounts[iteratorI];
            accounts.erase(accounts.begin() + iteratorI);
            return true;
        }
    }
    return false;
}

std::vector<Account *> Bank::getAccountsByUser(User *user)
{
    std::vector<Account *> result;
    std::vector<int> userAccountNumbers;

    if (user->getRole() == Role::ACCOUNT_HOLDER)
    {
        AccountHolder *holder = static_cast<AccountHolder *>(user);
        userAccountNumbers = holder->getAccountNumbers();
    }
    else if (user->getRole() == Role::ADMIN)
    {
        Admin *admin = static_cast<Admin *>(user);
        AccountHolder *profile = admin->getAccountHolderProfile();
        if (profile)
        {
            userAccountNumbers = profile->getAccountNumbers();
        }
    }

    for (Account *account : accounts)
    {
        for (int accountNumber : userAccountNumbers)
        {
            if (account->getAccountNumber() == accountNumber)
            {
                result.push_back(account);
                break;
            }
        }
    }
    return result;
}

bool Bank::removeUser(int userId, int requesterId)
{
    User *user = userManager->getUserById(userId);

    if (!user)
    {
        return false;
    }

    if (user->getRole() == Role::ADMIN && user->getUserId() == requesterId)
    {
        std::cout << "Admins cannot remove themselves" << std::endl;
        return false;
    }

    if (user->getRole() == Role::ADMIN)
    {
        Admin *admin = static_cast<Admin *>(user);
        AccountHolder *profile = admin->getAccountHolderProfile();

        if (profile && !profile->getAccountNumbers().empty())
        {
            AccountHolder *newHolder = new AccountHolder(
                AccountHolderInfo{
                    admin->getUserId(),
                    admin->getName(),
                    Role::ACCOUNT_HOLDER,
                    profile->getEmail(),
                    profile->getPhoneNumber()});

            newHolder->setAccounts(profile->getAccounts());

            Credential cred = userManager->getCredentialByUserId(userId);
            userManager->removeUser(userId);
            userManager->addUser(newHolder, cred.username, cred.password);

            std::cout << "Admin privileges removed" << std::endl;
            return true;
        }
        else
        {
            userManager->removeUser(userId);
            std::cout << "Admin removed." << std::endl;
            return true;
        }
    }

    if (user->getRole() == Role::ACCOUNT_HOLDER)
    {
        AccountHolder *holder = static_cast<AccountHolder *>(user);
        std::vector<Account *> accountToRemove = getAccountsByUser(user);
        for (Account *account : accountToRemove)
        {
            closeAccount(account->getAccountNumber());
        }
    }

    userManager->removeUser(userId);
    return true;
}

User *Bank::getUser(int userId) { return userManager->getUserById(userId); }

const std::vector<Account *> &Bank::getAllAccounts() const { return accounts; }

bool Bank::removeAccount(int userId, int accountNumber)
{
    User *user = userManager->getUserById(userId);

    if (!user || user->getRole() != Role::ACCOUNT_HOLDER)
    {
        return false;
    }

    return closeAccount(accountNumber);
}

AccountHolder *Bank::getAccountHolderById(int userId)
{
    User *user = getUser(userId);

    if (user && user->getRole() == Role::ACCOUNT_HOLDER)
    {
        return static_cast<AccountHolder *>(user);
    }
    return nullptr;
}

int Bank::getUserIdByAccount(Account *account)
{
    const std::vector<User *> &allUsers = userManager->getAllUsers();

    for (int iteratorI = 0; iteratorI < allUsers.size(); iteratorI++)
    {
        User *user = allUsers[iteratorI];

        if (user->getRole() == Role::ACCOUNT_HOLDER)
        {
            AccountHolder *holder = static_cast<AccountHolder *>(user);
            const std::vector<int> &accountNumbers = holder->getAccountNumbers();

            for (int iteratorJ = 0; iteratorJ < accountNumbers.size(); iteratorJ++)
            {
                if (accountNumbers[iteratorJ] == account->getAccountNumber())
                {
                    return holder->getUserId();
                }
            }
        }
        else if (user->getRole() == Role::ADMIN)
        {
            Admin *admin = static_cast<Admin *>(user);
            AccountHolder *linkedHolder = admin->getAccountHolderProfile();

            if (linkedHolder != nullptr)
            {
                const std::vector<int> &accountNumbers = linkedHolder->getAccountNumbers();

                for (int iteratorJ = 0; iteratorJ < accountNumbers.size(); iteratorJ++)
                {
                    if (accountNumbers[iteratorJ] == account->getAccountNumber())
                    {
                        return linkedHolder->getUserId();
                    }
                }
            }
        }
    }

    return -1;
}

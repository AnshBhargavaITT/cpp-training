#ifndef UTILS_H
#define UTILS_H
#include<string>

std::string getCurrentDate() ;

bool isValidEmail(const std::string& email);

bool isValidPhone(const std::string& phone);

bool isValidName(const std::string& name);

bool isNumeric(const std::string& input);

void clearInputBuffer();

bool isValidPassword(const std::string& password);

#endif

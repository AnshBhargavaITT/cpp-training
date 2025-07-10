#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
    std::vector<int> inputArray;
    int n;
    std::cout << "Enter the value of n" << std::endl;
    std::cin >> n;

    std::cout << "Enter Input Array" << std::endl;
    for(int iteratorI = 0; iteratorI < n; iteratorI++)
    {
        int value;
        std::cin >> value;
        inputArray.push_back(value);
    }

    int target;
    std::cout << "Enter Target" << std::endl;
    std::cin >> target;

    std::sort(inputArray.begin(), inputArray.end());
    std::vector<std::vector<int>> ans;

    for(int iteratorI = 0; iteratorI < inputArray.size(); iteratorI++)
    {
        if(iteratorI != 0 && inputArray.at(iteratorI) == inputArray.at(iteratorI - 1))
        {
            continue;
        }

        int iteratorJ = iteratorI + 1;
        int iteratorK = inputArray.size() - 1;

        while(iteratorJ < iteratorK)
        {
            int sum = inputArray.at(iteratorI) + inputArray.at(iteratorJ) + inputArray.at(iteratorK);

            if(sum < target)
            {
                iteratorJ++;
            }
            else if(sum > target)
            {
                iteratorK--;
            }
            else 
            {
                std::vector<int> temp = {inputArray[iteratorI], inputArray[iteratorJ], inputArray[iteratorK]};
                ans.push_back(temp);
                iteratorJ++;
                iteratorK--;

                while(iteratorJ < iteratorK && inputArray.at(iteratorJ) == inputArray.at(iteratorJ - 1))
                {
                    iteratorJ++;
                }

                while(iteratorJ < iteratorK && inputArray.at(iteratorK) == inputArray.at(iteratorK + 1))
                {
                    iteratorK--;
                }
            }
        }
    }

    for (const auto& triplet : ans) 
    {
        std::cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]\n";
    }

    return 0;
}

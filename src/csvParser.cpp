#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "csvParser.h"

int countQuotes(const std::string &completeLine);

std::vector<std::string> parseLine(const std::string &completeLine);

CSVParser::ParseStatus CSVParser::parse(const std::string &filename)
{
    try
    {
        std::ifstream file;
        file.open(filename, std::ios::in);
        if (!file.is_open())
        {
            std::cout << "Cannot open CSV file : " << filename << std::endl;
            return ParseStatus::FileNotFound;
        }

        file.seekg(0, std::ios::end);
        if (file.tellg() == 0)
        {
            std::cout << "CSV file is empty : " << filename << std::endl;
            return ParseStatus::FileEmpty;
        }
        file.seekg(0, std::ios::beg);

        std::string line;
        std::string completeLine;
        bool inQuotes = false;

        while (std::getline(file, line))
        {
            if (!completeLine.empty())
            {
                completeLine += "\n";
            }

            completeLine += line;

            int quoteCount = countQuotes(completeLine);
            inQuotes = (quoteCount % 2 != 0);

            if (inQuotes)
            {
                continue;
            }

            std::vector<std::string> row = parseLine(completeLine);

            std::cout << "Parsed CSV :" << std::endl;
            for (int iteratorI = 0; iteratorI < row.size(); iteratorI++)
            {
                std::cout << "[" << row[iteratorI] << "] ";
            }
            std::cout << std::endl;

            completeLine = "";
        }

        return ParseStatus::Success;
    }
    catch (const std::exception &e)
    {
        std::cerr << "CSVParser Exception: " << e.what() << std::endl;
        return ParseStatus::UnknownError;
    }
}

int countQuotes(const std::string &completeLine)
{
    int quoteCount = 0;
    for (int iteratorI = 0; iteratorI < completeLine.size(); iteratorI++)
    {
        if (completeLine[iteratorI] == '"')
        {
            quoteCount++;
        }
    }
    return quoteCount;
}

std::vector<std::string> parseLine(const std::string &completeLine)
{
    std::vector<std::string> row;
    std::string cell;
    bool insideQuotes = false;

    for (int iteratorI = 0; iteratorI < completeLine.size(); iteratorI++)
    {
        char character = completeLine[iteratorI];

        if (character == '"')
        {
            if (insideQuotes && iteratorI + 1 < completeLine.size() && completeLine[iteratorI + 1] == '"')
            {
                cell += '"';
                iteratorI++;
            }
            else
            {
                insideQuotes = !insideQuotes;
            }
        }
        else if (character == ',' && !insideQuotes)
        {
            row.push_back(cell);
            cell = "";
        }
        else
        {
            cell += character;
        }
    }
    row.push_back(cell);
    return row;
}

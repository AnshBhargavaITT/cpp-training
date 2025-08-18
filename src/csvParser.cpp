#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "csvParser.h"

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
        std::vector<std::vector<std::string>> parsedData;

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
            parsedData.push_back(row);
            completeLine = "";
        }
        printParsedData(parsedData);
        return ParseStatus::Success;
    }
    catch (const std::exception &e)
    {
        std::cerr << "CSVParser Exception: " << e.what() << std::endl;
        return ParseStatus::UnknownError;
    }
}

int CSVParser::countQuotes(const std::string &completeLine)
{
    int quoteCount = 0;
    for (int rowIteratorI = 0; rowIteratorI < completeLine.size(); rowIteratorI++)
    {
        if (completeLine[rowIteratorI] == '"')
        {
            quoteCount++;
        }
    }
    return quoteCount;
}

std::vector<std::string> CSVParser::parseLine(const std::string &completeLine)
{
    std::vector<std::string> row;
    std::string cell;
    bool insideQuotes = false;

    for (int rowIteratorI = 0; rowIteratorI < completeLine.size(); rowIteratorI++)
    {
        char character = completeLine[rowIteratorI];

        if (character == '"')
        {
            if (insideQuotes && rowIteratorI + 1 < completeLine.size() && completeLine[rowIteratorI + 1] == '"')
            {
                cell += '"';
                rowIteratorI++;
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

void CSVParser::printParsedData(const std::vector<std::vector<std::string>> &data)
{
    std::cout<<"Parsed CSV : "<<std::endl;
    for (std::vector<std::vector<std::string>>::const_iterator rowIteratorI = data.begin(); rowIteratorI != data.end(); rowIteratorI++)
    {
        for (std::vector<std::string>::const_iterator cellIteratorI = rowIteratorI->begin(); cellIteratorI != rowIteratorI->end(); cellIteratorI++)
        {
            std::cout << "[" << *cellIteratorI << "] ";
        }
        std::cout << std::endl;
    }
}

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

        headerRow.clear();
        csvData.clear();

        bool isFirstLine = true;

        std::cout << "Parsed CSV :" << std::endl;

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

            if (isFirstLine)
            {
                headerRow = row;
                isFirstLine = false;
            }
            else
            {
                csvData.push_back(row);
            }

            for (int iteratorI = 0; iteratorI < (int)row.size(); iteratorI++)
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
        std::cout << "CSVParser Exception: " << e.what() << std::endl;
        return ParseStatus::UnknownError;
    }
}

int CSVParser::countQuotes(const std::string &completeLine)
{
    int quoteCount = 0;
    for (int rowIteratorI = 0; rowIteratorI < (int)completeLine.size(); rowIteratorI++)
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

    for (int rowIteratorI = 0; rowIteratorI < (int)completeLine.size(); rowIteratorI++)
    {
        char character = completeLine[rowIteratorI];

        if (character == '"')
        {
            if (insideQuotes && rowIteratorI + 1 < (int)completeLine.size() && completeLine[rowIteratorI + 1] == '"')
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

std::string CSVParser::getCell(int rowIndex, const std::string &columnName) const
{
    int colIndex = -1;
    for (int iteratorI = 0; iteratorI < (int)headerRow.size(); iteratorI++)
    {
        if (headerRow[iteratorI] == columnName)
        {
            colIndex = iteratorI;
            break;
        }
    }

    if (colIndex == -1)
    {
        std::cout << "Column name not found: " << columnName << std::endl;
        return "";
    }

    if (rowIndex < 0 || rowIndex >= (int)csvData.size())
    {
        std::cout << "Row index out of range: " << rowIndex << std::endl;
        return "";
    }

    if (colIndex >= (int)csvData[rowIndex].size())
    {
        std::cout << "Column index out of range in row data." << std::endl;
        return "";
    }

    return csvData[rowIndex][colIndex];
}

int CSVParser::getRowCount() const
{
    return (int)csvData.size();
}

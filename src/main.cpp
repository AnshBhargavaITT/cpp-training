#include <iostream>
#include <string>
#include <fstream>
#include "parser.h"
#include "jsonParser.h"
#include "csvParser.h"
#include "xmlParser.h"

enum class FileType
{
    JSON = 1,
    CSV,
    XML,
    Invalid
};

bool fileExists(const std::string &filename);

void parseStatus(Parser::ParseStatus status);

int main()
{
    std::string filename;
    int choice = 0;

    std::cout << "Select file type to parse:" << std::endl;
    std::cout << "1. JSON" << std::endl;
    std::cout << "2. CSV" << std::endl;
    std::cout << "3. XML" << std::endl;
    std::cout << "Enter your choice : " << std::endl;
    std::cin >> choice;
    std::cin.ignore();

    FileType fileType = FileType::Invalid;

    switch (choice)
    {
    case 1:
        fileType = FileType::JSON;
        break;

    case 2:
        fileType = FileType::CSV;
        break;

    case 3:
        fileType = FileType::XML;
        break;

    default:
        std::cout << "Invalid file type " << std::endl;
        return 1;
    }

    std::cout << "Enter file path: " << std::endl;
    std::getline(std::cin, filename);

    if (filename.empty())
    {
        std::cout << "Filename cannot be empty" << std::endl;
        return 1;
    }

    if (!fileExists(filename))
    {
        std::cout << "File does not exist : " << filename << std::endl;
        return 1;
    }

    Parser *parser = nullptr;

    switch (fileType)
    {
    case FileType::JSON:
        parser = new JSONParser();
        break;

    case FileType::CSV:
        parser = new CSVParser();
        break;

    case FileType::XML:
        parser = new XMLParser();
        break;

    default:
        std::cout << "Failed to create parser" << std::endl;
        return 1;
    }

    Parser::ParseStatus status = parser->parse(filename);
    parseStatus(status);

    delete parser;
    return 0;
}

bool fileExists(const std::string &filename)
{
    std::ifstream file(filename);
    return file.is_open();
}

void parseStatus(Parser::ParseStatus status)
{
    if (status == Parser::ParseStatus::Success)
    {
        std::cout << "Parsing completed successfully" << std::endl;
    }
    else if (status == Parser::ParseStatus::FileNotFound)
    {
        std::cout << "Error: File not found" << std::endl;
    }
    else if (status == Parser::ParseStatus::FileEmpty)
    {
        std::cout << "Error: File is empty" << std::endl;
    }
    else if (status == Parser::ParseStatus::ParseError)
    {
        std::cout << "Error: Parse error occurred" << std::endl;
    }
    else if (status == Parser::ParseStatus::ParseFailed)
    {
        std::cout << "Error: Parse failed" << std::endl;
    }
    else if (status == Parser::ParseStatus::InvalidRootType)
    {
        std::cout << "Error: Invalid root type in file" << std::endl;
    }
    else
    {
        std::cout << "Error: Unknown error occurred" << std::endl;
    }
}

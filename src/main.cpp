#include <iostream>
#include <string>
#include <fstream>
#include "parser.h"
#include "jsonParser.h"
#include "csvParser.h"
#include "xmlParser.h"

bool fileExists(const std::string &filename)
{
    std::ifstream file;
    file.open(filename, std::ios::in);
    if (file.is_open())
    {
        file.close();
        return true;
    }
    return false;
}

int main()
{
    std::string fileType;
    std::string filename;

    std::cout << "Enter file type : " << std::endl;
    std::getline(std::cin, fileType);

    if (fileType != "json" && fileType != "csv" && fileType != "xml")
    {
        std::cout << "Invalid file type" << std::endl;
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

    Parser *parser = NULL;
    if (fileType == "json")
    {
        parser = new JSONParser();
    }
    else if (fileType == "csv")
    {
        parser = new CSVParser();
    }
    else if (fileType == "xml")
    {
        parser = new XMLParser();
    }

    if (parser == NULL)
    {
        std::cout << "Failed to create parser" << std::endl;
        return 1;
    }

    parser->parse(filename);

    delete parser;
    return 0;
}

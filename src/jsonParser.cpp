#include "jsonParser.h"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

JSONParser::ParseStatus JSONParser::parse(const std::string &filename)
{
    try
    {
        std::ifstream file(filename, std::ios::in);
        if (!file.is_open())
        {
            std::cout << "Cannot open JSON file : " << filename << std::endl;
            return ParseStatus::FileNotFound;
        }

        file.seekg(0, std::ios::end);
        if (file.tellg() == 0)
        {
            std::cout << "JSON file is empty : " << filename << std::endl;
            return ParseStatus::FileEmpty;
        }
        file.seekg(0, std::ios::beg);
        nlohmann::json json;
        file >> json;

        if (!json.is_object() && !json.is_array())
        {
            std::cout << "JSON root is neither object nor array: " << filename << std::endl;
            return ParseStatus::InvalidRootType;
        }

        std::cout << "Parsed JSON:" << std::endl;
        printJsonFormatted(json, 0);

        return ParseStatus::Success;
    }
    catch (const nlohmann::json::parse_error &e)
    {
        std::cout << "JSON Parse Error: " << e.what() << std::endl;
        return ParseStatus::ParseError;
    }
    catch (const std::exception &e)
    {
        std::cout << "JSONParser Exception: " << e.what() << std::endl;
        return ParseStatus::UnknownError;
    }
}

void JSONParser::printJsonFormatted(const nlohmann::json &node, int indentLevel)
{
    std::string padding(indentLevel, ' ');

    if (node.is_object())
    {
        for (nlohmann::json::const_iterator nodeIteratorI = node.begin(); nodeIteratorI != node.end(); nodeIteratorI++)
        {
            std::cout << padding << nodeIteratorI.key() << ": ";
            if (nodeIteratorI.value().is_primitive())
            {
                std::cout << nodeIteratorI.value() << std::endl;
            }
            else
            {
                std::cout << std::endl;
                printJsonFormatted(nodeIteratorI.value(), indentLevel + 4);
            }
        }
    }
    else if (node.is_array())
    {
        for (nlohmann::json::const_iterator nodeIteratorI = node.begin(); nodeIteratorI != node.end(); nodeIteratorI++)
        {
            if (nodeIteratorI->is_primitive())
            {
                std::cout << padding << "- " << *nodeIteratorI << std::endl;
            }
            else
            {
                std::cout << padding << "-" << std::endl;
                printJsonFormatted(*nodeIteratorI, indentLevel + 4);
            }
        }
    }
}

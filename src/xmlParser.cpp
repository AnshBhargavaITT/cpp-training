#include "xmlParser.h"
#include <iostream>
#include <fstream>
#include <pugixml.hpp>

void printXmlNode(const pugi::xml_node &node, int indentLevel);

XMLParser::ParseStatus XMLParser::parse(const std::string &filename)
{
    try
    {
        std::ifstream file(filename, std::ios::in | std::ios::binary);
        if (!file)
        {
            std::cerr << "Error: Cannot open XML file: " << filename << std::endl;
            return ParseStatus::FileNotFound;
        }

        file.seekg(0, std::ios::end);
        if (file.tellg() == 0)
        {
            std::cerr << "Error: XML file is empty: " << filename << std::endl;
            return ParseStatus::FileEmpty;
        }

        file.seekg(0, std::ios::beg);

        pugi::xml_document document;
        pugi::xml_parse_result result = document.load(file);

        file.close();

        if (!result)
        {
            std::cerr << "Parse failed: " << result.description() << " (offset: " << result.offset << ")" << std::endl;
            return ParseStatus::ParseFailed;
        }

        std::cout << "Parsed XML:\n";
        printXmlNode(document.document_element(), 0);

        return ParseStatus::Success;
    }
    catch (const std::exception &e)
    {
        std::cerr << "XMLParser Exception: " << e.what() << std::endl;
        return ParseStatus::UnknownError;
    }
}

void printXmlNode(const pugi::xml_node &node, int indentLevel)
{
    std::string padding(indentLevel * 2, ' ');

    std::cout << padding << node.name();

    pugi::xml_attribute attribute = node.first_attribute();
    while (attribute)
    {
        std::cout << " [" << attribute.name() << "=\"" << attribute.value() << "\"]";
        attribute = attribute.next_attribute();
    }

    pugi::xml_node child = node.first_child();
    if (child && child.type() == pugi::node_pcdata && !child.next_sibling())
    {
        std::cout << ": " << child.value();
    }
    std::cout << "\n";

    pugi::xml_node childNode = node.first_child();
    while (childNode)
    {
        if (childNode.type() == pugi::node_element)
        {
            printXmlNode(childNode, indentLevel + 1);
        }
        childNode = childNode.next_sibling();
    }
}

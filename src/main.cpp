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

void parseStatus(IParser::ParseStatus status);

void handleCSV(const std::string &filename);

void handleJSON(const std::string &filename);

void handleXML(const std::string &filename);

int main()
{
    std::string filename;
    int choice = 0;

    std::cout << "Select file type to parse:" << std::endl;
    std::cout << "1. JSON" << std::endl;
    std::cout << "2. CSV" << std::endl;
    std::cout << "3. XML" << std::endl;
    std::cout << "Enter your choice : " <<std::endl;
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
        std::cout << "File does not exist: " << filename << std::endl;
        return 1;
    }

    switch (fileType)
    {
    case FileType::JSON:
        handleJSON(filename);
        break;
    case FileType::CSV:
        handleCSV(filename);
        break;
    case FileType::XML:
        handleXML(filename);
        break;
    default:
        std::cout << "Unknown file type" << std::endl;
        return 1;
    }

    return 0;
}

bool fileExists(const std::string &filename)
{
    std::ifstream file(filename);
    return file.is_open();
}

void parseStatus(IParser::ParseStatus status)
{
    switch (status)
    {
    case IParser::ParseStatus::Success:
        std::cout << "Parsing completed successfully" << std::endl;
        break;

    case IParser::ParseStatus::FileNotFound:
        std::cout << "Error: File not found" << std::endl;
        break;

    case IParser::ParseStatus::FileEmpty:
        std::cout << "Error: File is empty" << std::endl;
        break;

    case IParser::ParseStatus::ParseError:
        std::cout << "Error: Parse error occurred" << std::endl;
        break;

    case IParser::ParseStatus::ParseFailed:
        std::cout << "Error: Parse failed" << std::endl;
        break;

    case IParser::ParseStatus::InvalidRootType:
        std::cout << "Error: Invalid root type in file" << std::endl;
        break;

    default:
        std::cout << "Error: Unknown error occurred" << std::endl;
        break;
    }
}

void handleCSV(const std::string &filename)
{
    CSVParser parser;
    IParser::ParseStatus status = parser.parse(filename);
    parseStatus(status);
    if (status != IParser::ParseStatus::Success) { return; }

    int totalRows = parser.getRowCount(); 
    for (int rowIndex = 0; rowIndex < totalRows; rowIndex++)
    {
        std::string name = parser.getCell(rowIndex, "name");
        std::string city = parser.getCell(rowIndex, "city");

        std::cout << "Person: " << name << " | City: " << city << std::endl;
    }
}

void handleJSON(const std::string &filename)
{
    JSONParser parser;
    IParser::ParseStatus status = parser.parse(filename);
    parseStatus(status);
    if (status != IParser::ParseStatus::Success) { return; }

    nlohmann::json people = parser.getParsedData("people");
    if (people.is_array() && people.size() > 0)
    {
        std::cout << "First person's name: " << people[0]["name"] << std::endl;
        std::cout << "First person's city: " << people[0]["details"]["address"]["city"] << std::endl;
    }
}

void handleXML(const std::string &filename)
{
    XMLParser parser;
    IParser::ParseStatus status = parser.parse(filename);
    parseStatus(status);
    if (status != IParser::ParseStatus::Success) { return; }

    pugi::xml_node peopleNode = parser.getXmlDocument().child("people");

    for (pugi::xml_node personNode = peopleNode.child("person"); personNode; personNode = personNode.next_sibling("person"))
    {
        pugi::xml_node nameNode = personNode.child("name");
        pugi::xml_node cityNode = personNode.child("details").child("address").child("city");

        std::string name = nameNode ? nameNode.child_value() : "No Name";
        std::string city = cityNode ? cityNode.child_value() : "No City";

        std::cout << "Person: " << name << " | City: " << city << std::endl;
    }
}

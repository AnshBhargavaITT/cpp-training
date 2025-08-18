#ifndef XMLPARSER_H
#define XMLPARSER_H
#include "parser.h"
#include <string>
#include <pugixml.hpp>

class XMLParser : public IParser
{
public:
    ParseStatus parse(const std::string &filename) override;

private:
    void printXmlNode(const pugi::xml_node &node, int indentLevel);
};

#endif

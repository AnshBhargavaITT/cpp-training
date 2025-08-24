#ifndef XMLPARSER_H
#define XMLPARSER_H
#include "parser.h"
#include <string>
#include <pugixml.hpp>

class XMLParser : public IParser
{
public:
    ParseStatus parse(const std::string &filename) override;

    const pugi::xml_document& getXmlDocument() const;

    pugi::xml_node getNode(const std::string &xpath) const;

private:
    void printXmlNode(const pugi::xml_node &node, int indentLevel);

    pugi::xml_document xmlDocument;
};

#endif

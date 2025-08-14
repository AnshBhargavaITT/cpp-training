#ifndef XMLPARSER_H
#define XMLPARSER_H
#include "parser.h"
#include <string>

class XMLParser : public Parser
{
public:
    ParseStatus parse(const std::string &filename) override;
};

#endif

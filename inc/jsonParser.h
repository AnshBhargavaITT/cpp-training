#ifndef JSONPARSER_H
#define JSONPARSER_H
#include "parser.h"
#include <string>

class JSONParser : public Parser
{
public:
    ParseStatus parse(const std::string &filename) override;
};

#endif

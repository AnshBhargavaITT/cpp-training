#ifndef JSONPARSER_H
#define JSONPARSER_H
#include "parser.h"
#include <string>
#include <nlohmann/json.hpp>

class JSONParser : public Parser
{
public:
    ParseStatus parse(const std::string &filename) override;

private:
    void printJsonFormatted(const nlohmann::json &node, int indentLevel = 0);
};

#endif

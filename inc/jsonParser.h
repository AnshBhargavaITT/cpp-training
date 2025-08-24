#ifndef JSONPARSER_H
#define JSONPARSER_H
#include "parser.h"
#include <string>
#include <nlohmann/json.hpp>

class JSONParser : public IParser
{
public:
    ParseStatus parse(const std::string &filename) override;

    const nlohmann::json &getJson() const;

    nlohmann::json getParsedData(const std::string &key) const;

private:
    void printJsonFormatted(const nlohmann::json &node, int indentLevel = 0);

    nlohmann::json parsedData;
};

#endif

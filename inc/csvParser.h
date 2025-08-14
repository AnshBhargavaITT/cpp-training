#ifndef CSVPARSER_H
#define CSVPARSER_H
#include "parser.h"
#include <string>

class CSVParser : public Parser
{
public:
    ParseStatus parse(const std::string &filename) override;
};

#endif

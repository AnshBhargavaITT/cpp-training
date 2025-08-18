#ifndef CSVPARSER_H
#define CSVPARSER_H
#include "parser.h"
#include <vector>
#include <string>

class CSVParser : public IParser
{
public:
    ParseStatus parse(const std::string &filename) override;

private:
    int countQuotes(const std::string &line);

    void printParsedData(const std::vector<std::vector<std::string>> &data);
    
    std::vector<std::string> parseLine(const std::string &line);
};

#endif

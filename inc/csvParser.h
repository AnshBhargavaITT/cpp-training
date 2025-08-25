#ifndef CSVPARSER_H
#define CSVPARSER_H
#include "parser.h"
#include <vector>
#include <string>

class CSVParser : public IParser
{
public:
    ParseStatus parse(const std::string &filename) override;

    std::string getCell(int rowIndex, const std::string &columnName) const;

    int getRowCount() const;
    
private:
    int countQuotes(const std::string &line);
    
    std::vector<std::string> parseLine(const std::string &line);

    std::vector<std::string> headerRow;  

    std::vector<std::vector<std::string>> csvData;
};

#endif

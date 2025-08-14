#ifndef PARSER_H
#define PARSER_H
#include <string>

class Parser
{
public:
    enum class ParseStatus
    {
        Success,
        FileNotFound,
        FileEmpty,
        ParseError,
        ParseFailed,
        InvalidRootType,
        UnknownError
    };
    virtual ~Parser() {}
    virtual ParseStatus parse(const std::string &filename) = 0;
};

#endif

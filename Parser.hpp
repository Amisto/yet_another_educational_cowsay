#ifndef PARSER_H
#define PARSER_H

#include <string>
using std::string;

class Parser {

    string cowsource, cloudsource, message;
    char background;
    struct Flags {
        bool cowsource = false;
        bool cloudsource = false;
        bool eyes = false;
        bool tongue = false;
        bool background = false;
    } flags;

public:

    Parser(int argc, char *argv[]);
    ~Parser();

    string getCow();
    string getCloud();
    char getFill();
    string getMessage();

};

#endif

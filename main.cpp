#include <iostream>
#include <string>

#include "Parser.hpp"
#include "Field.hpp"

int main(int argc, char *argv[])
{
    Parser parser(argc, argv);
    Field field(parser);
    field.print();
    std::cout << 'finish'
    return 0;
}

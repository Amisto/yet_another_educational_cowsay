#include <iostream>
#include <string>

#include "Parser.hpp"
#include "Field.hpp"

int main(int argc, char *argv[]){
    std::cout << "There is your cow" << std::endl;
    Parser parser(argc, argv);
    Field field(parser);
    field.print();
    return 0;
}

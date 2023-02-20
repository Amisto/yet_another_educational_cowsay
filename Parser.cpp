#include "Parser.hpp"
#include "Converter.hpp"
#include <filesystem>
namespace fs = std::filesystem;

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

Parser::Parser(int argc, char *argv[])
{
    int arg = 0;
    while (arg < argc - 1)
    {
        arg++;
        string tmp(argv[arg]);
        if (tmp == "-h")
        {
            cout << "-f [cowname] to change the cow source" << endl;
            cout << "-c [cloudname] to change the cloud source" << endl;
            cout << "-s to change weather to snow" << endl;
            cout << "-r to change weather to rain" << endl;
            cout << "-m to change weather to money" << endl;
            cout << "-l to see list of all cows and clouds" << endl;
            cout << "-b [filename] to convert bmp image into cow" << endl;
            exit(0);
        }
        if (tmp == "-f")
        {
            arg++;
            cowsource = argv[arg];
            flags.cowsource = true;
        }
        else if (tmp == "-c")
        {
            arg++;
            cloudsource = argv[arg];
            flags.cloudsource = true;
        }
        else if (tmp == "-s")
            flags.snow = true;
        else if (tmp == "-r")
            flags.rain = true;
        else if (tmp == "-m")
            flags.money = true;
        else if (tmp == "-l"){
            std::cout << "cows:" << std::endl;
            std::string path = "cows";
            for (const auto & entry : fs::directory_iterator(path))
                std::cout << entry.path() << std::endl;
            std::cout << "clouds:" << std::endl;
            path = "clouds";
            for (const auto & entry : fs::directory_iterator(path))
                std::cout << entry.path() << std::endl;
            exit(0);
        }
        else if (tmp == "-b") {
            arg++;
            Converter newcow(argv[arg]);
            cowsource = argv[arg];
            flags.cowsource = true;
        }
        else while (arg < argc)
        {
            string tmp(argv[arg]);
            message += tmp;
            message += ' ';
            arg++;
        }
    }
    if (message.size() == 0)
    {
        string tmp;
        while (cin >> tmp)
            message += tmp + " ";
    }
}

Parser::~Parser() {}

string Parser::getCow()
{
    if (flags.cowsource)
        return cowsource;
    else
        return "cow";
}

string Parser::getCloud()
{
    if (flags.cloudsource)
        return cloudsource;
    else
        return "cloud";
}

char Parser::getFill()
{
    if (flags.snow)
        return '*';
    else if (flags.rain)
        return '.';
    else if (flags.money)
        return '$';
    else
        return ' ';
}

string Parser::getMessage()
{
    return message;
}

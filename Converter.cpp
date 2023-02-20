#include <fstream>
#include <iostream>
#include "Converter.hpp"
using namespace std;

Converter::Converter(string fname) {
    FILE* f = fopen((fname + ".bmp").c_str(), "rb");
    unsigned char info[54];

    fread(info, sizeof(unsigned char), 54, f);

    int width = *(int*)&info[18];
    int height = *(int*)&info[22];

    unsigned long int size = (width * 3 + 3) & (~3);
    unsigned char* data = new unsigned char[size];
    char symbols[] = " .,*(/%#@";
    int** grayscale = new int*[height];
    for (int i = 0; i < height; i++) {
        grayscale[i] = new int[width];
    }

    for(int i = 0; i < height; i++)
    {
        fread(data, sizeof(unsigned char), size, f);
        for (int j = 0; j < width * 3; j += 3)
        {
            int gray = (int)data[j] * 0.114 + (int)data[j + 1] * 0.587 + (int)data[j + 2] * 0.299;
            grayscale[height - i - 1][j / 3] = 255 - gray;
        }
    }

    fclose(f);
    delete[] data;

    ofstream result;
    result.open(("./cows/" + fname + ".cow").c_str());

    int max_size = 30;

    int nheight = (height < max_size ? height : max_size) * 2 / 3;
    int nwidth = width < max_size ? width : max_size;
    float dh = 1 + (float) (height - nheight) / (nheight - 1);
    float dw = 1 + (float) (width - nwidth) / (nwidth - 1);

    for (int i = 0; i < height; i += dh) {
        for (int j = 0; j < width; j += dw) {
            result << symbols[grayscale[i][j] * 8 / 255];
        }
        result << endl;
    }

    result.close();

    for (int i = 0; i < height; i++) {
        delete[] grayscale[i];
    }
    delete[] grayscale;
}

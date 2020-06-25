#include <iostream>
#include <cmath>
#include <fstream>
#include <list>
#include "pcm_generator.h"

typedef unsigned long DWORD;
typedef unsigned short WORD;

int main() {
    std::list<float> pcm = generator("notes.txt");
    std::ofstream output("file.wav", std::ofstream::binary);

    output << "RIFF";

    DWORD dword = 36 + sizeof(float) * pcm.size();
    output.write((char *)(&(dword)), sizeof(DWORD));

    output << "WAVE";

    output << "fmt ";

    dword = 16;
    output.write((char *)(&(dword)), sizeof(DWORD));

    WORD word = 1; // type format & mono
    output.write((char *)(&(word)), sizeof(WORD));
    output.write((char *)(&(word)), sizeof(WORD));

    // sample rate
    dword = 96000;
    output.write((char *)(&(dword)), sizeof(DWORD));

    // bytes/s
    dword = 96000*sizeof(float);
    output.write((char *)(&(dword)), sizeof(DWORD));

    // alignment
    word = sizeof(float);
    output.write((char *)(&(word)), sizeof(WORD));

    // bits/sample
    word = sizeof(float)*8;
    output.write((char *)(&(word)), sizeof(WORD));

    output << "data";

    // data size
    dword = sizeof(float) * pcm.size();
    output.write((char *)(&(dword)), sizeof(DWORD));

    for (float i : pcm) { // writing data
        output.write(reinterpret_cast<const char *>(&i), sizeof(float));
    }
    output.close();
    std::system("ffplay -f f32le -ar 96000 file.wav");
    return 0;
}
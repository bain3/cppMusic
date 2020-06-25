#include <iostream>
#include <cmath>
#include <fstream>
#include <list>
#include "pcm_generator.h"

typedef unsigned long DWORD, *PDWORD, *LPDWORD;
typedef unsigned short WORD, *PWORD, *LPWORD;

int main() {
    std::list<float> pcm = generator("notes.txt");
    std::ofstream output("file.dat");
    output << "RIFF";
    DWORD sze = 36 + sizeof(float) * pcm.size();
    std::cout << sze;
    output.write(reinterpret_cast<const char *>(&sze), sizeof(DWORD));
    output << "WAVE";
    output << "fmt ";



//    for (float i : pcm) { // writing data
//        output.write((char *)(&i), sizeof(float));
//    }
    output.close();
//    std::system("ffplay -f f32le -ar 48000 -loglevel quiet file.dat");
    return 0;
}
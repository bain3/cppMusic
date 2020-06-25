#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <list>
float pi = std::acosf(-1);
float VOLUME = 0.5;
float sample_rate = 48000;

float freq(const float& hz);

std::list<float> generator(const std::string& filename) {
    std::list<float> array;
    std::ifstream notes(filename);
    float hz, duration;
    while (notes >> hz >> duration) {
        float frequency = freq(hz);
        for (int i = 0; i <= (int)(duration*sample_rate)-1; i++) {
            array.push_back(std::sinf(((float) i) * frequency) * VOLUME);
        }
    }
    return array;
}

float freq(const float& hz) {
    return 2 * pi * hz / sample_rate;
}
#include <cstdint>
#include <cstring>
#include "CroixPharma.h"
#include <string>
#include <fstream>
#include <vector>
#include <array>

CroixPharma croix;
uint8_t bitmap[SIZE][SIZE];
std::vector<std::string> lines;

std::array<const char *, 21> pharmaFiles = {{
    "output/out1.png.pharma",
    "output/out2.png.pharma",
    "output/out3.png.pharma",
    "output/out4.png.pharma",
    "output/out5.png.pharma",
    "output/out6.png.pharma",
    "output/out7.png.pharma",
    "output/out8.png.pharma",
    "output/out9.png.pharma",
    "output/out10.png.pharma",
    "output/out11.png.pharma",
    "output/out12.png.pharma",
    "output/out13.png.pharma",
    "output/out14.png.pharma",
    "output/out15.png.pharma",
    "output/out16.png.pharma",
    "output/out17.png.pharma",
    "output/out18.png.pharma",
    "output/out19.png.pharma",
    "output/out20.png.pharma",
    "output/out21.png.pharma",
}};

std::size_t fileIndex = 0;

void displayImage()
{
    memset(bitmap, 0, sizeof(bitmap));

    for (std::size_t y = 0; y < lines.size(); y++) {
        for (std::size_t x = 0; x < lines[y].length(); x++) {
            if (lines[y][x] == 'x')
                bitmap[y][x] = 1;
        }
    }

    croix.writeBitmap(bitmap);
}

int main() {
    if (wiringPiSetupGpio() < 0) {
        return 1;
    }

    croix.begin();

    while (true) {
        lines.clear();

        std::ifstream file(pharmaFiles[fileIndex % pharmaFiles.size()]);
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        fileIndex++;

        displayImage();
        delay(100);
    }

    return 0;
}

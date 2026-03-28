#include <cstdint>
#include <cstring>
#include "CroixPharma.h"
#include <string>
#include <fstream>
#include <vector>

CroixPharma croix;
uint8_t bitmap[SIZE][SIZE];
std::vector<std::string> lines;

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

    std::ifstream file("image.txt");
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    while (true) {
        displayImage();
        delay(200);
    }

    return 0;
}

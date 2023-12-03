#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <array>

std::array<std::array<int, 4>, 1000> assignments;
std::array<int, 4> pairs;
std::string line;
int counterAll = 0;
int counterAny = 0;

std::array<int, 4> parseLine(std::string line) {
    std::array<int, 4> result;
    size_t size = 0;
    std::stringstream ss(line);
    for (int i; ss >> i;) {
        result[size++] = i;
        if (ss.peek() == ',' || ss.peek() == '-') {
            ss.ignore();
        }
    }
    return result;
}

bool rangeIsSubset(std::array<int, 4> range) {
    if(range[0] <= range[2] && range[1] >= range[3]) {
        return true;
    } else if (range[0] >= range[2] && range[1] <= range[3]) {
        return true;
    } else {
        return false;
    }
}

bool rangeOverlaps(std::array<int, 4> ranges) {
    int start = std::max(ranges[0], ranges[2]);
    int end = std::min(ranges[1], ranges[3]);

    return start <= end;
}

int main () {
    std::ifstream myfile("04-input.txt");
    if (!myfile) {
        std::cerr << "Unable to open file";
        exit(1);
    }
    int i = 0;
    while (getline(myfile, line)) {
        assignments[i] = parseLine(line);
        i++;
    }
    myfile.close();
    for (auto& a : assignments) {
       if (rangeIsSubset(a)) {
           counterAll++;
       }
       if (rangeOverlaps(a)) {
           counterAny++;
       }
    }
    std::cout << "Part 1: " << counterAll << std::endl;
    std::cout << "Part 2: " << counterAny << std::endl;
    return 0;
}
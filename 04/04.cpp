#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <array>

std::array<std::array<int, 4>, 1000> assignments;
std::array<int, 4> pairs;
std::string line;
int counter = 0;

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
           counter++;
       }
    }
    std::cout << "Part 1: " << counter << std::endl;
    return 0;
}
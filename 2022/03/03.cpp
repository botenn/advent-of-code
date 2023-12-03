#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <set>
#include <algorithm>
#include <cctype>

int getPriority(char c) {
    if(std::islower(c)) {
        return c - 96;
    } else {
        return c - 38;
    }
}

int main(){
    std::string line;
    std::string rucksack;
    std::array<std::string, 300> rucksacks;
    std::array<char, 300> items;
    std::ifstream myfile("03-input.txt");
    if (!myfile) {
        std::cerr << "Unable to open file";
        exit(1);
    }
    int i = 0;
    while (getline(myfile, line)) {
        rucksack = line;
        rucksacks[i] = rucksack;
        i++;
    }
    myfile.close();
    i = 0;
    for (auto& r : rucksacks) {
        std::size_t mid = r.size() / 2;
        std::string first_half = r.substr(0, mid);
        std::string second_half = r.substr(mid);
        for (auto& c : first_half) {
            if(std::size_t found = second_half.find(c) != std::string::npos) {
                items[i] = c;
                i++;
                break;
            }
        }
    }
    int total = 0;
    for (auto& item : items) {
        total += getPriority(item);
    }
    std::cout << "Part 1: " << total << std::endl;

    i = 0;
    int badges = 0;
    while (i < 300) {
        for (auto& c : rucksacks[i]) {
            if (std::size_t found = rucksacks[i+1].find(c) != std::string::npos) {
                if (std::size_t found = rucksacks[i+2].find(c) != std::string::npos) {
                    badges += getPriority(c);
                    i += 3;
                    break;
                }
            }
        }

    }
       
    std::cout << "Part 2: " << badges << std::endl;
    return 0;
}
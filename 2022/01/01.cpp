#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

int main () {
    std::string line;
    std::vector<std::vector<int>> elves_calories;
    std::vector<int> calories;
    std::ifstream myfile; myfile.open("01-input.txt");
    if (myfile.is_open()) {
        int summed_calories = 0;
        while (getline(myfile, line)) {
            if (line.size() == 0) {
                calories.push_back(summed_calories);
                summed_calories = 0;
            }
            else {
                summed_calories += std::stoi(line);
            }
        }
        myfile.close();
    }
    else std::cout << "Unable to open file";
    std::sort(calories.begin(), calories.end(), std::greater<int>());
    std::cout << calories[0] << std::endl;
    std::cout << accumulate(calories.begin(), calories.begin() + 3, 0) << std::endl;
}
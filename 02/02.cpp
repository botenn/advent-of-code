#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <set>

/// @brief 
/// @param round 
/// @param key_set 
/// @param add_score 
/// @param score_key 
/// @param score 
void update_score(const std::array<char, 2>& round, const std::set<std::array<char, 2>>& key_set, int add_score, std::unordered_map<char, int>& score_key, int& score) {
    for (const auto& pair : key_set) {
        if (pair[0] == round[0]) {
            score += add_score;
            score += score_key[pair[1]];
            break;
        }
    }
}

int main (){
    int score = 0;
    std::string line;
    std::vector<std::array<char, 2>> rounds;
    std::unordered_map<char, int> score_key = {
        {'A', 1},
        {'B', 2},
        {'C', 3},
        {'X', 1},
        {'Y', 2},
        {'Z', 3}
    };
    std::set<std::array<char, 2>> draw_key = {
        {'A', 'X'},
        {'B', 'Y'},
        {'C', 'Z'}
    };
    std::set<std::array<char, 2>> win_key = {
        {'A', 'Y'},
        {'B', 'Z'},
        {'C', 'X'}
    };
    std::set<std::array<char, 2>> loss_key = {
        {'A', 'Z'},
        {'B', 'X'},
        {'C', 'Y'}
    };

    std::ifstream myfile("02-input.txt");
    if (!myfile) {
        std::cerr << "Unable to open file";
        exit(1);
    }
    char a, b;
    while (myfile >> a >> b) {
        std::array<char, 2> round = {a, b};
        rounds.push_back(round);
    }
    myfile.close();
    for (auto round : rounds) {
        if (draw_key.find(round) != draw_key.end()) {
            score += 3;
            score += score_key[round[1]];
        } else if (win_key.find(round) != win_key.end()) {
            score += 6;
            score += score_key[round[1]];
        } else if (loss_key.find(round) != loss_key.end()) {
            score += score_key[round[1]];
        }
    }

    std::cout << "Part 1: " << score << std::endl;

    score = 0;

    for (auto round : rounds) {
        if (round[1] == 'X') {
            update_score(round, loss_key, 0, score_key, score);
        } else if (round[1] == 'Y') {
            update_score(round, draw_key, 3, score_key, score);
        } else if (round[1] == 'Z') {
            update_score(round, win_key, 6, score_key, score);
        }
    }

    std::cout << "Part 2: " << score << std::endl;
}
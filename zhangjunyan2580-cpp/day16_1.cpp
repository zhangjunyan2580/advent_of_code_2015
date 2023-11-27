#include <iostream>
#include <string>
#include <unordered_map>
#include "pystrlib.hpp"

std::unordered_map<std::string, int> A[501];
std::unordered_map<std::string, int> S;

int main() {
    freopen("day16.txt", "r", stdin);
    {
        std::string str;
        for (int i = 1; i <= 500; ++i) {
            std::getline(std::cin, str);
            std::vector<std::string> p = lib::split(lib::split(str, ": ", 1)[1], ", ");
            for (const std::string &S : p) {
                std::vector<std::string> vec = lib::split(S, ": ");
                A[i][vec[0]] = std::stoi(vec[1]);
            }
        }
        S["children"] = 3;
        S["cats"] = 7;
        S["samoyeds"] = 2;
        S["pomeranians"] = 3;
        S["akitas"] = 0;
        S["vizslas"] = 0;
        S["goldfish"] = 5;
        S["trees"] = 3;
        S["cars"] = 2;
        S["perfumes"] = 1;
    }
    for (int i = 1; i <= 500; ++i) {
        bool match = true;
        for (const auto &[k, v] : S)
            if (A[i].count(k) && A[i][k] != v) { match = false; break; }
        if (match) std::cout << i << ' ';
    }
    return 0;
}
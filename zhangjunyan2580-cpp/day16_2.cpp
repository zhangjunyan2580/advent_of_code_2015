#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include "pystrlib.hpp"

std::unordered_map<std::string, int> A[501];
std::unordered_map<std::string, std::function<bool(int)> > S;

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
        S["children"] = [](int i){ return i == 3; };
        S["cats"] = [](int i){ return i > 7; };
        S["samoyeds"] = [](int i){ return i == 2; };
        S["pomeranians"] = [](int i){ return i < 3; };
        S["akitas"] = [](int i){ return i == 0; };
        S["vizslas"] = [](int i){ return i == 0; };
        S["goldfish"] = [](int i){ return i < 5; };
        S["trees"] = [](int i){ return i > 3; };
        S["cars"] = [](int i){ return i == 2; };
        S["perfumes"] = [](int i){ return i == 1; };
    }
    for (int i = 1; i <= 500; ++i) {
        bool match = true;
        for (const auto &[k, v] : S)
            if (A[i].count(k) && !v(A[i][k])) { match = false; break; }
        if (match) std::cout << i << ' ';
    }
    return 0;
}
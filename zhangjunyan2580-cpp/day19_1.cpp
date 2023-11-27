#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include "pystrlib.hpp"

int n;
std::unordered_set<std::string> S;
std::unordered_map<std::string, std::string> M;
std::string str;

int main() {
    freopen("day19.txt", "r", stdin);
    {
        std::string line;
        while (std::getline(std::cin, line)) {
            if (line == "") break;
            auto vec = lib::split(line, " => ");
            M[vec[0]] = vec[1];
        }
        std::getline(std::cin, str);
    }
    for (const auto &[k, v] : M)
        for (unsigned i = k.size(); i <= str.size(); ++i)
            if (str.substr(i - k.size(), k.size()) == k) {
                std::string copy = str;
                S.insert(copy.replace(i - k.size(), k.size(), v));
            }
    std::cout << S.size();
    return 0;
}
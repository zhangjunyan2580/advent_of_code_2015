#include <iostream>
#include <string>
#include "pystrlib.hpp"

int S = 2503;
std::vector<int> o, i, v, s, x;

int main() {
    freopen("day14.txt", "r", stdin);
    {
        std::string line;
        while (std::getline(std::cin, line)) {
            std::vector<std::string> vec = lib::split(line, " ");
            v.push_back(std::stoi(vec[3])); o.push_back(std::stoi(vec[6])); i.push_back(std::stoi(vec[13]));
        }
    }
    s.resize(o.size()); x.resize(o.size());
    for (int t = 0; t < S; ++t) {
        int p = 0;
        for (unsigned j = 0; j < o.size(); ++j) (t % (o[j] + i[j]) < o[j]) && (x[j] += v[j]), (x[j] > x[p]) && (p = j);
        for (unsigned j = 0; j < o.size(); ++j) (x[j] == x[p]) && ++s[j];
    }
    std::cout << *std::max_element(s.begin(), s.end());
    return 0;
}
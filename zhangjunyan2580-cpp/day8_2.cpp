#include <iostream>
#include <string>
#include <algorithm>

std::string line;
int len_diff;

int main() {
    freopen("day8.txt", "r", stdin);
    while (std::getline(std::cin, line))
        len_diff += 2 + std::count_if(line.begin(), line.end(), [](char c){ return c == '\\' || c == '"'; });
    std::cout << len_diff;
    return 0;
}
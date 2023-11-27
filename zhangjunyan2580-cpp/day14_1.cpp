#include <iostream>
#include <string>
#include "pystrlib.hpp"

int S = 2503, ans;

int main() {
    freopen("day14.txt", "r", stdin);
    {
        std::string line;
        while (std::getline(std::cin, line)) {
            std::vector<std::string> vec = lib::split(line, " ");
            int v = std::stoi(vec[3]), o = std::stoi(vec[6]), i = std::stoi(vec[13]);
            int t = v * (S / (o + i) * o + (S % (o + i) >= o ? o : S % (o + i)));
            if (t > ans) ans = t;
        }
    }
    std::cout << ans;
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <regex>

int light[1000][1000];
std::string ins;

std::regex pattern("(.+) (\\d+),(\\d+) through (\\d+),(\\d+)");

int main() {
    freopen("day6.txt", "r", stdin);
    while (std::getline(std::cin, ins)) {
        std::match_results<std::string::iterator> result;
        if (std::regex_match(ins.begin(), ins.end(), result, pattern)) {
            auto it = result.begin();
            std::string op = (++it)->str();
            int type = op == "turn off" ? 0 : op == "turn on" ? 1 : 2;
            int x1 = std::stoi((++it)->str());
            int y1 = std::stoi((++it)->str());
            int x2 = std::stoi((++it)->str());
            int y2 = std::stoi((++it)->str());
            for (int i = x1; i <= x2; ++i)
                for (int j = y1; j <= y2; ++j)
                    if (type == 0) light[i][j] && --light[i][j];
                    else light[i][j] += type;
        }
    }
    long long c = 0;
    for (int i = 0; i < 1000; ++i)
        for (int j = 0; j < 1000; ++j)
            c += light[i][j];
    std::cout << c << std::endl;
    return 0;
}
#include <iostream>
#include <regex>

std::string json;
std::regex pattern("-?\\d+");
int sum;

int main() {
    freopen("day12.txt", "r", stdin);
    std::getline(std::cin, json);
    auto it = std::sregex_iterator(json.begin(), json.end(), pattern);
    auto it_e = std::sregex_iterator();
    while (it != it_e) sum += std::stoi(it++->str());
    std::cout << sum;
    return 0;
}
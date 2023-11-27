#include <iostream>
#include <string>
#include <unordered_map>
#include "pystrlib.hpp"
#include <string.h>

int n;
std::string str;
std::unordered_map<std::string, int> mapping;
int token_count;

int rules[256][256];
int steps[500][500][256];

std::vector< std::pair<int, int> > p[256];

std::vector<int> sp;
bool is_atom[256];

std::vector<int> parse_string(std::string str) {
    unsigned i = 0;
    std::vector<int> ans;
    for (; i < str.size(); ) {
        std::string token;
        if (i == str.size() - 1u || isupper(str[i + 1])) token = str.substr(i, 1), ++i;
        else token = str.substr(i, 2), i += 2;
        if (mapping.count(token)) ans.push_back(mapping[token]);
        else ans.push_back(++token_count), mapping[token] = token_count;
    }
    return ans;
}

int main() {
    freopen("day19.txt", "r", stdin);
    {
        std::string line;
        while (std::getline(std::cin, line)) {
            if (line == "") break;
            auto vec = lib::split(line, " => ");
            int to = parse_string(vec[0])[0];
            std::vector<int> from = parse_string(vec[1]);
            if (from.size() >= 3) {
                // rules[from[0]][from[1]] = token_count + 1;
                p[token_count + 1].emplace_back(from[0], from[1]);
                for (unsigned i = 2; i < from.size() - 1; ++i)
                    p[token_count + i].emplace_back(token_count + i - 1, from[i]);
                    // rules[token_count + i - 1][from[i]] = token_count + i;
                // rules[token_count + from.size() - 2][from.back()] = to;
                p[to].emplace_back(token_count + from.size() - 2, from.back());
                token_count += from.size() - 2;
            } else p[to].emplace_back(from[0], from[1]);
            // rules[from[0]][from[1]] = to;
        }
        std::getline(std::cin, str);
        std::getline(std::cin, str);
        sp = parse_string(str);
    }
    for (const auto &[x, y] : mapping) is_atom[y] = 1;
    int n = sp.size();
    memset(steps, -1, sizeof(steps));
    for (int i = 0; i < n; ++i)
        steps[i][i + 1][sp[i]] = 0;
    for (int i = 2; i <= n; ++i)
        for (int l = 0, r = i; r <= n; ++l, ++r)
            for (int k = 1; k <= token_count; ++k)
                for (const auto &[x, y] : p[k])
                    for (int u = l + 1; u < r; ++u)
                        if (steps[l][u][x] != -1 && steps[u][r][y] != -1 && (steps[l][r][k] == -1 || steps[l][u][x] + steps[u][r][y] + is_atom[k] < steps[l][r][k]))
                            steps[l][r][k] = steps[l][u][x] + steps[u][r][y] + is_atom[k];
    std::cout << steps[0][n][mapping["e"]] << std::endl;
    return 0;
}
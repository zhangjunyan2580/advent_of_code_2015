#include <iostream>
#include <string>
#include <vector>
#include "pystrlib.hpp"

unsigned reg[2];
int inst[100][3];

#define HLF 1
#define TPL 2
#define INC 3
#define JMP 4
#define JIE 5
#define JIO 6
#define HLT 0

int main() {
    freopen("day23.txt", "r", stdin);
    {
        std::string line;
        int i = 0;
        while (std::getline(std::cin, line)) {
            auto [a, b, c] = lib::partition(line, " ");
            if (a == "hlf") inst[i][0] = HLF, inst[i][1] = c[0] - 'a';
            else if (a == "tpl") inst[i][0] = TPL, inst[i][1] = c[0] - 'a';
            else if (a == "inc") inst[i][0] = INC, inst[i][1] = c[0] - 'a';
            else if (a == "jmp") inst[i][0] = JMP, inst[i][1] = std::stoi(c);
            else if (a == "jie") {
                inst[i][0] = JIE;
                auto [d, e, f] = lib::partition(c, ", ");
                inst[i][1] = d[0] - 'a'; inst[i][2] = std::stoi(f);
            } else if (a == "jio") {
                inst[i][0] = JIO;
                auto [d, e, f] = lib::partition(c, ", ");
                inst[i][1] = d[0] - 'a'; inst[i][2] = std::stoi(f);
            }
            ++i;
        }
    }
    reg[0] = 1;
    int pt = 0;
    while (inst[pt][0] != HLT) {
        switch (inst[pt][0]) {
            case HLF: reg[inst[pt][1]] >>= 1; ++pt; break;
            case TPL: reg[inst[pt][1]] *= 3; ++pt; break;
            case INC: ++reg[inst[pt][1]]; ++pt; break;
            case JMP: pt += inst[pt][1]; break;
            case JIE: (reg[inst[pt][1]] & 1) ? ++pt : (pt += inst[pt][2]); break;
            case JIO: (reg[inst[pt][1]] == 1) ? (pt += inst[pt][2]) : ++pt; break;
        }
    }
    std::cout << reg[1];
    return 0;
}
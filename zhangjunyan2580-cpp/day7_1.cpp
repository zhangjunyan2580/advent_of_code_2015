#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <stack>
#include "pystrlib.hpp"

#define _AND 1
#define _OR 2
#define _LSHIFT 3
#define _RSHIFT 4
#define _NOT 5
#define _MOV 6

struct Node {
    unsigned short val;
    bool computed;
    int type;
    std::string source1, source2;
    int degree;
};

std::unordered_map<std::string, Node> val;
std::unordered_map< std::string, std::vector<std::string> > out;

std::pair<std::string, Node> parse(const std::string &str) {
    std::vector<std::string> splitted = lib::split(str, " ");
    if (splitted.size() == 5u) {
        if (splitted[1] == "AND")
            return std::make_pair(splitted[4], (Node) { (unsigned short) 0, false, _AND, splitted[0], splitted[2], 2 });
        if (splitted[1] == "OR")
            return std::make_pair(splitted[4], (Node) { (unsigned short) 0, false, _OR, splitted[0], splitted[2], 2 });
        if (splitted[1] == "LSHIFT")
            return std::make_pair(splitted[4], (Node) { (unsigned short) 0, false, _LSHIFT, splitted[0], splitted[2], 2 });
        return std::make_pair(splitted[4], (Node) { (unsigned short) 0, false, _RSHIFT, splitted[0], splitted[2], 2 });
    }
    if (splitted.size() == 4u)
        return std::make_pair(splitted[3], (Node) { (unsigned short) 0, false, _NOT, splitted[1], "", 1 });
    if (isdigit(splitted[0][0]))
        return std::make_pair(splitted[2], (Node) { (unsigned short) std::stoi(splitted[0]), true, 0, "", "", 0 });
    return std::make_pair(splitted[2], (Node) { (unsigned short) 0, false, _MOV, splitted[0], "", 1 });
}

unsigned short get_v(std::string k) {
    if (isdigit(k[0])) return std::stoi(k);
    return val[k].val;
}

int main() {
    freopen("day7.txt", "r", stdin);
    std::string inst;
    while (std::getline(std::cin, inst))
        val.insert(parse(inst));
    for (auto &[_, v] : val) {
        if (v.source1 != "") {
            if (isdigit(v.source1[0])) --v.degree;
            else {
                if (!out.count(v.source1)) out[v.source1] = std::vector<std::string>();
                out[v.source1].push_back(_);
            }
        }
        if (v.source2 != "") {
            if (isdigit(v.source2[0])) --v.degree;
            else {
                if (!out.count(v.source2)) out[v.source2] = std::vector<std::string>();
                out[v.source2].push_back(_);
            }
        }
    }
    std::stack<std::string> S;
    for (const auto &[_, v] : val)
        if (v.computed) S.push(_);
    while (!S.empty()) {
        std::string u = S.top(); S.pop();
        for (const std::string &to : out[u]) {
            Node &v = val[to];
            if (!--v.degree) {
                v.computed = true;
                switch (v.type) {
                    case _AND: v.val = get_v(v.source1) & get_v(v.source2); break;
                    case _OR: v.val = get_v(v.source1) | get_v(v.source2); break;
                    case _LSHIFT: v.val = get_v(v.source1) << get_v(v.source2); break;
                    case _RSHIFT: v.val = get_v(v.source1) >> get_v(v.source2); break;
                    case _NOT: v.val = ~get_v(v.source1); break;
                    case _MOV: v.val = get_v(v.source1); break;
                }
                S.push(to);
            }
        }
    }
    std::cout << val["a"].val << std::endl;
    return 0;
}
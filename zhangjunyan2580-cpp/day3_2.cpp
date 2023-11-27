#include <stdio.h>
#include <set>
#include <utility>

std::set< std::pair<int, int> > pos;
std::pair<int, int> npos, rpos;

char str[200005];

int main() {
    freopen("day3.txt", "r", stdin);
    scanf("%s", str);
    pos.insert(npos); pos.insert(rpos);
    for (char *s = str; *s; ++s) {
        std::pair<int, int> &N = ((s - str) & 1) ? npos : rpos;
        if (*s == '<') --N.first;
        else if (*s == '>') ++N.first;
        else if (*s == '^') --N.second;
        else ++N.second;
        pos.insert(N);
    }
    printf("%u", pos.size());
    return 0;
}
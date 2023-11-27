#include <stdio.h>
#include <set>
#include <utility>

std::set< std::pair<int, int> > pos;
std::pair<int, int> npos;

char str[200005];

int main() {
    freopen("day3.txt", "r", stdin);
    scanf("%s", str);
    pos.insert(npos);
    for (char *s = str; *s; ++s, pos.insert(npos))
        if (*s == '<') --npos.first;
        else if (*s == '>') ++npos.first;
        else if (*s == '^') --npos.second;
        else ++npos.second;
    printf("%u", pos.size());
    return 0;
}
#include <stdio.h>
#include <string.h>

bool nice(char *str) {
    int count[32];
    memset(count, 0, sizeof(count));
    bool twice = false;
    while (*str) {
        if ((*str == 'a' && *(str + 1) == 'b')
         || (*str == 'c' && *(str + 1) == 'd')
         || (*str == 'p' && *(str + 1) == 'q')
         || (*str == 'x' && *(str + 1) == 'y')) return false;
        if (*str ==  *(str + 1)) twice = true;
        ++count[*str & 31];
        ++str;
    }
    return twice && (count[1] + count[5] + count[9] + count[15] + count[21] >= 3);
}

char str[50];
int ans;

int main() {
    freopen("day5.txt", "r", stdin);
    while (~scanf(" %s", str))
        if (nice(str)) ++ans;
    printf("%d\n", ans);
    return 0;
}
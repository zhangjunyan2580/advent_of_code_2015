#include <stdio.h>

char str[200005];
int v;

int main() {
    freopen("day1.txt", "r", stdin);
    scanf("%s", str);
    char *s = str;
    for (; *s; ++s) {
        if (v < 0) { printf("%d\n", s - str); return 0; }
        if (*s == '(') ++v; else --v;
    }
}
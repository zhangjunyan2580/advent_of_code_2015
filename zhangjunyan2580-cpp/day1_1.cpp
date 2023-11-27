#include <stdio.h>

char str[200005];
int v;

int main() {
    freopen("day1.txt", "r", stdin);
    scanf("%s", str);
    char *s = str;
    for (; *s; ++s)
        if (*s == '(') ++v; else --v;
    printf("%d\n", v);
    return 0;
}
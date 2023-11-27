#include <stdio.h>
#include <string.h>

bool nice(char *str) {
    int len = strlen(str);
    bool twice = false;
    for (char a = 'a'; a <= 'z'; ++a)
        for (char b = 'a'; b <= 'z'; ++b) {
            bool found = false;
            for (int i = 0; i < len; ++i)
                if (str[i] == a && str[i + 1] == b) {
                    if (found) { twice = true; goto check_twice; }
                    found = true; ++i;
                }
        }
    check_twice:
    if (!twice) return false;
    for (int i = 0; i < len; ++i)
        if (str[i] == str[i + 2]) return true;
    return false;
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
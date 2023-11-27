#include <iostream>
#include <string.h>

int s[105][105];
int SZ = 100;

void go() {
    int p[105][105];
    memset(p, 0, sizeof(p));
    for (int i = 1; i <= SZ; ++i)
        for (int j = 1; j <= SZ; ++j) {
            int on = 0;
            for (int k = i - 1; k <= i + 1; ++k)
                for (int l = j - 1; l <= j + 1; ++l)
                    if (k != i || l != j) on += s[k][l];
            p[i][j] = (s[i][j] && (on == 2 || on == 3)) || (!s[i][j] && on == 3);
        }
    memcpy(s, p, sizeof(p));
}

int main() {
    freopen("day18.txt", "r", stdin);
    std::string k;
    for (int i = 1; i <= SZ; ++i) {
        std::cin >> k;
        for (int j = 0; j < SZ; ++j)
            s[i][j + 1] = k[j] == '#';
    }
    int p = 100; while (p--) go();
    int ans = 0;
    for (int i = 1; i <= SZ; ++i)
        for (int j = 1; j <= SZ; ++j)
            ans += s[i][j];
    std::cout << ans;
    return 0;
}
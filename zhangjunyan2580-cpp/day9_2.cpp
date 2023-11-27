#include <iostream>
#include <stdio.h>
#include <string.h>
#include "pystrlib.hpp"

int a[8][8], dp[256][8];
constexpr int SZ = 8;
std::string line;

int main() {
    freopen("day9.txt", "r", stdin);
    int i = 0, j = 1;
    while (std::getline(std::cin, line)) {
        a[i][j] = a[j][i] = std::stoi(lib::rsplit(line, " ").back());
        if (j == SZ - 1) ++i, j = i + 1;
        else ++j;
    }
    int MX = 1 << SZ;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < SZ; ++i) dp[1 << i][i] = 0;
    for (int i = 0; i < SZ; ++i)
        for (int S = 0; S < MX; ++S)
            for (int j = 0; j < SZ; ++j)
                if (((S >> j) & 1) && dp[S][j] == 0x3f3f3f3f) {
                    dp[S][j] = 0;
                    for (int k = 0; k < SZ; ++k)
                        if (j != k && ((S >> k) & 1) && dp[S & ~(1 << j)][k] + a[k][j] > dp[S][j])
                            dp[S][j] = dp[S & ~(1 << j)][k] + a[k][j];
                }
    int ans = 0;
    for (int i = 0; i < SZ; ++i)
        if (dp[MX - 1][i] > ans) ans = dp[MX - 1][i];
    std::cout << ans << std::endl;
    return 0;
}
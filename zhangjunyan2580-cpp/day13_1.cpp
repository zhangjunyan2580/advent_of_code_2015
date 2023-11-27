#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
#include "pystrlib.hpp"

int a[8][8], dp[256][8];
constexpr int SZ = 8;

int main() {
    freopen("day13.txt", "r", stdin);
    {
        int i = 0, j = 1;
        std::string line;
        while (std::getline(std::cin, line)) {
            std::vector<std::string> v = lib::split(line, " ");
            a[i][j] = (v[2] == "gain" ? 1 : -1) * std::stoi(v[3]);
            if (j == SZ - 1) ++i, j = 0;
            else ++j;
            if (i == j) ++j;
        }
    }
    for (int i = 0; i < SZ; ++i)
        for (int j = i + 1; j < SZ; ++j)
            a[i][j] += a[j][i], a[j][i] = a[i][j];
    memset(dp, 0x3f, sizeof(dp));
    dp[1][0] = 0;
    int MX = 1 << SZ;
    for (int i = 0; i < SZ; ++i)
        for (int S = 1; S < MX; ++S)
            for (int j = 0; j < SZ; ++j)
                if (!((S >> j) & 1)) {
                    int T = S | (1 << j);
                    for (int k = 0; k < SZ; ++k)
                        if (((S >> k) & 1) && dp[S][k] != 0x3f3f3f3f && (dp[T][j] == 0x3f3f3f3f || dp[S][k] + a[k][j] > dp[T][j]))
                            dp[T][j] = dp[S][k] + a[k][j];
                }
    int ans = 0;
    for (int i = 1; i < SZ; ++i)
        if (dp[MX - 1][i] + a[i][0] > ans)
            ans = dp[MX - 1][i] + a[i][0];
    std::cout << ans;
    return 0;
}
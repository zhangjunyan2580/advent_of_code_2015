#include <iostream>
#include <string>

int S = 150;
long long dp[151][20];

int main() {
    freopen("day17.txt", "r", stdin);
    dp[0][0] = 1;
    int s;
    while (std::cin >> s)
        for (int j = S; j >= s; --j)
            for (int k = 19; k >= 0; --k)
                dp[j][k] += dp[j - s][k - 1];
    for (int k = 0; k < 19; ++k)
        if (dp[S][k]) { std::cout << dp[S][k]; break; }
    return 0;
}
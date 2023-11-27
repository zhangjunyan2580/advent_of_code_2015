#include <iostream>
#include <string>

int S = 150;
long long dp[151];

int main() {
    freopen("day17.txt", "r", stdin);
    dp[0] = 1;
    int s;
    while (std::cin >> s)
        for (int j = S; j >= s; --j)
            dp[j] += dp[j - s];
    std::cout << dp[S];
    return 0;
}
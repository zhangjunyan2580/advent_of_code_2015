#include <iostream>

int a, sum[20000005];

int main() {
    std::cin >> a; a = (a / 11) + !!(a % 11);
    for (int i = 1; i <= a; ++i) {
        for (int j = i; j <= a; j += i) {
            sum[j] += i;
            if (j >= 50 * i) break;
        }
        if (sum[i] >= a) { std::cout << i << '\n'; break; }
    }
    return 0;
}
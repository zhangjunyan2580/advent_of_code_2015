#include <iostream>
#include <string>
#include "pystrlib.hpp"

int c[4], d[4], f[4], t[4], k[4];
long long ans;

int main() {
    freopen("day15.txt", "r", stdin);
    {
        std::string line; int i = 0;
        while (std::getline(std::cin, line)) {
            std::vector<std::string> vec = lib::split(line + ",", " ");
#define Q(x, y) x[i] = std::stoi(vec[y].substr(0, vec[y].size() - 1))
            Q(c, 2); Q(d, 4); Q(f, 6); Q(t, 8); Q(k, 10);
#undef Q
            ++i;
        }
    }
    for (int i = 0; i <= 100; ++i)
        for (int j = 0; j <= 100 - i; ++j)
            for (int l = 0; l <= 100 - i - j; ++l) {
                int m = 100 - i - j - l;
#define C(x) int x##t = std::max(i * x[0] + j * x[1] + l * x[2] + m * x[3], 0)
                C(c); C(d); C(f); C(t); C(k);
#undef C
                if (kt != 500) continue;
                long long ts = (long long) ct * dt * ft * tt;
                (ts > ans) && (ans = ts);
            }
    std::cout << ans;
    return 0;
}
#include <stdio.h>
#include <algorithm>

int x, y, z;
long long val;

int main() {
    freopen("day2.txt", "r", stdin);
    while (~scanf("%dx%dx%d", &x, &y, &z))
        val += x * y * z + 2 * std::min({x + y, x + z, y + z});
    printf("%lld\n", val);
    return 0;
}
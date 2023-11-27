#include <iostream>
#include <algorithm>
#include <vector>

int n, a[105], h, s, p[1000005], m, al = 0x3f3f3f3f;
long long aq = 0x3f3f3f3f3f3f3f3f;

bool u[105];

void dfs(int l, int c, int v) {
    if (c == s / 3) { p[++m] = v; return; }
    if (c > s / 3) return; 
    for (int i = l - 1; i >= 0; --i) dfs(i, c + a[i], v | (1 << i)); 
}

int main() {
    freopen("day24.txt", "r", stdin);
    while (std::cin >> a[n++]) s += a[n - 1];
    --n;
    std::sort(a, a + n);
    dfs(n, 0, 0);
    for (int i = m; i; --i) {
        int l = __builtin_popcount(p[i]);
        if (l > al) continue;
        bool found = false;
        for (int j = 1; j <= m; ++j)
            if (!(p[j] & p[i])) { found = true; break; }
        if (found) {
            long long q = 1;
            for (int j = 0; j < n; ++j) ((p[i] >> j) & 1) && (q *= a[j]);
            if (l < al || q < aq) al = l, aq = q;
        }
    }
    std::cout << aq << std::endl;
    return 0;
}
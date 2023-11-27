#include <iostream>

int hp = 100;
int HP, ATK, DEF, ans = 0x3f3f3f3f;

int div_up(int a, int b) { !b && (b = 1); return a / b + !!(a % b); }

void dfs(int k, int atk, int def, int cost) {
    if (k == 1) {
        dfs(2, 4, 0, 8); dfs(2, 5, 0, 10);
        dfs(2, 6, 0, 25); dfs(2, 7, 0, 40);
        dfs(2, 8, 0, 74);
    } else if (k == 2) {
        dfs(3, atk, 0, cost); dfs(3, atk, 1, cost + 13);
        dfs(3, atk, 2, cost + 31); dfs(3, atk, 3, cost + 53);
        dfs(3, atk, 4, cost + 75); dfs(3, atk, 5, cost + 102);
    } else if (k == 3) {
        dfs(4, atk, def, cost); dfs(4, atk + 1, def, cost + 25);
        dfs(4, atk + 2, def, cost + 50); dfs(4, atk + 3, def, cost + 100);
        dfs(4, atk, def + 1, cost + 20); dfs(4, atk, def + 2, cost + 40);
        dfs(4, atk, def + 3, cost + 80); dfs(4, atk + 3, def, cost + 75);
        dfs(4, atk + 4, def, cost + 125); dfs(4, atk + 1, def + 1, cost + 45);
        dfs(4, atk + 1, def + 2, cost + 65); dfs(4, atk + 1, def + 3, cost + 105);
        dfs(4, atk + 5, def, cost + 150); dfs(4, atk + 2, def + 1, cost + 70);
        dfs(4, atk + 2, def + 2, cost + 90); dfs(4, atk + 2, def + 3, cost + 130);
        dfs(4, atk + 3, def + 1, cost + 120); dfs(4, atk + 3, def + 2, cost + 140);
        dfs(4, atk + 3, def + 3, cost + 180); dfs(4, atk, def + 3, cost + 60);
        dfs(4, atk, def + 4, cost + 100); dfs(4, atk, def + 5, cost + 120);
    } else if (k == 4) {
        int rp = div_up(HP, atk - DEF), rb = div_up(hp, ATK - def);
        if (rp <= rb && cost < ans) ans = cost;
    }
}

int main() {
    std::cin >> HP >> ATK >> DEF;
    dfs(1, 0, 0, 0);
    std::cout << ans;
    return 0;
}
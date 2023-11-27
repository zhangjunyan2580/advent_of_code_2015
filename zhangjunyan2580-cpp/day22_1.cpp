#include <iostream>
#include <unordered_map>
#include <tuple>
#include <queue>

int hp = 50, mana = 500;
int HP, ATK;

// hp, mana, HP, shield, poison, recharge, turn
typedef std::tuple<int, int, int, int, int, int, int> Node;

std::priority_queue< std::pair<int, Node>, std::vector< std::pair<int, Node> >, std::greater< std::pair<int, Node> > > Q;

int ans = 0x3f3f3f3f;

int main() {
    std::cin >> HP >> ATK;
    Q.emplace(0, std::make_tuple(hp, mana, HP, 0, 0, 0, 0));
    while (!Q.empty()) {
        auto [d, N] = Q.top(); Q.pop();
        auto [hp, mana, HP, shield, poison, recharge, turn] = N;
        if (d >= ans) break;
        if (shield) --shield;
        if (poison) HP -= 3, --poison;
        if (recharge) mana += 101, --recharge;
        if (HP <= 0) { if (d < ans) ans = d; continue; }
        if (turn) {
            if (shield) hp -= ATK - 7;
            else hp -= ATK;
            if (hp <= 0) continue;
            Q.emplace(d, std::make_tuple(hp, mana, HP, shield, poison, recharge, 0));
        } else {
            if (mana < 53) continue;
            if (HP <= 4) { if (d + 53 < ans) { ans = d + 53; continue; } }
            else Q.emplace(d + 53, std::make_tuple(hp, mana - 53, HP - 4, shield, poison, recharge, 1));
            if (mana >= 73) Q.emplace(d + 73, std::make_tuple(hp + 2, mana - 73, HP - 2, shield, poison, recharge, 1));
            if (mana >= 113 && !shield) Q.emplace(d + 113, std::make_tuple(hp, mana - 113, HP, 6, poison, recharge, 1));
            if (mana >= 173 && !poison) Q.emplace(d + 173, std::make_tuple(hp, mana - 173, HP, shield, 6, recharge, 1));
            if (mana >= 229 && !recharge) Q.emplace(d + 229, std::make_tuple(hp, mana - 229, HP, shield, poison, 5, 1));
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
#include <iostream>

std::string get_next(std::string str) {
    std::string ans;
    char now_char = str[0]; int now_count = 1;
    for (unsigned i = 1; i < str.size(); ++i)
        if (str[i] == now_char) ++now_count;
        else ans.push_back(now_count | 48), ans.push_back(now_char), now_char = str[i], now_count = 1;
    ans.push_back(now_count | 48); ans.push_back(now_char);
    return ans;
}

int main() {
    std::string str;
    std::cin >> str;
    for (int i = 40; i; --i) str = get_next(str);
    std::cout << str.size();
    return 0;
}
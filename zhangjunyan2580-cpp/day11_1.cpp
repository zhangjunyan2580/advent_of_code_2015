#include <iostream>
#include <string>

bool check(std::string str) {
    bool flag = true;
    for (char c : str)
        if (c == 'i' || c == 'o' || c == 'l')
            return false;
    for (int i = 0; i < 6; ++i)
        if (str[i] + 1 == str[i + 1] && str[i] + 2 == str[i + 2]) { flag = false; break; }
    if (flag) return false;
    flag = true;
    for (int i = 0; i < 7; ++i)
        if (str[i] == str[i + 1]) {
            if (flag) flag = false, ++i;
            else return true;
        }
    return false;
}

void inc(std::string &str) {
    for (int i = 7; i >= 0; --i)
        if (str[i] == 'z') str[i] = 'a';
        else { ++str[i]; break; }
}

std::string pass;

int main() {
    std::cin >> pass;
    while (!check((inc(pass), pass)));
    std::cout << pass;
    return 0;
}
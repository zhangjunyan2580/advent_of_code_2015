#include <iostream>
#include <string>

std::string line;
int len_raw, len;

int main() {
    freopen("day8.txt", "r", stdin);
    while (std::getline(std::cin, line)) {
        len_raw += line.size();
        line = line.substr(1, line.size() - 2);
        for (unsigned i = 0; i < line.size(); ) {
            ++len;
            if (line[i] == '\\') {
                if (line[i + 1] == '"' || line[i + 1] == '\\') i += 2;
                else if (line[i + 1] == 'x') i += 4;
            } else ++i;
        }
    }
    std::cout << len_raw - len;
    return 0;
}
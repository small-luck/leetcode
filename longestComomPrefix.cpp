#include <iostream>
#include <string>
#include <vector>

void longestCommomPrefix(std::vector<std::string>& strs)
{
    std::string res;
    uint32_t pos = 0;
    int i;
    int size = strs.size();
    char ch;
    
    if (size == 1) {
        std::cout << "res = " << strs[0] << std::endl;
        return;
    }
    
    for (i = 0; i < size; i++) {
        if (pos < strs[i].length()) {
            if (i == 0) {
                ch = strs[i][pos];
                continue;
            }
            if (ch != strs[i][pos])
                break;

            ch = strs[i][pos];
            if (i == size-1) {
                pos++;
                i = -1;
            }
        }
    }

    if (pos == 0) {
        std::cout << "res = " << " " << std::endl;
    }
    
    std::cout << "pos = " << pos << std::endl;

    res = strs[0].substr(0, pos);
    std::cout << "res = " << res << std::endl;
}

int main()
{
    std::vector<std::string> strs = {"aaa", "aa", "aaa"};
    longestCommomPrefix(strs);

    return 0;
}


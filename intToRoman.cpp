#include <iostream>
#include <string>
#include <map>

void intToRoman(int num)
{
    std::string res;
    std::map<int, std::string> values = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

    for (auto it = values.rbegin(); it != values.rend(); it++) {
        std::cout << "it->first = " << it->first << std::endl;
        while (num >= it->first) {
            num -= it->first;
            res.append(it->second);
        }
    }

    std::cout << "res = " << res << std::endl;
}

int main()
{
    intToRoman(3263);
    return 0;
}


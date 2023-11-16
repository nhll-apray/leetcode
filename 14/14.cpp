#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        while (1) {
            char c = strs[0][i];
            if (c == '\0') {
                return strs[0].substr(0, i);
            }
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] == '\0') {
                    return strs[0].substr(0, i);
                }
                if (strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
            i++;
        }
    }
};

int main()
{
    std::cout << "Hello World!\n";
}



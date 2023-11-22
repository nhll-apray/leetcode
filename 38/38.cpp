#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        for (int k = 2; k <= n; k++) {
            int i = 0;
            string nxt = "";
            while (i < str.length()) {
                char c = str[i];
                int num = 0;
                while (i < str.length() && str[i] == c) {
                    i++;
                    num++;
                }
                nxt += '0' + num;
                nxt += c;
            }
            str = nxt;
        }
        return str;
    }
};

int main()
{
    Solution sol;
    int n = 8;
    cout << sol.countAndSay(n);
}
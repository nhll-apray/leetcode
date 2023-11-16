#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.size();
        if (numRows == 1 || numRows >= len) {
            return s;
        }
        int k = numRows * 2 - 2;
        string ans = "";
        for (int i = 0; i < numRows; i++) {
            if (i == 0 || i == numRows - 1) {
                for (int j = i; j < len; j += k) {
                    ans += s[j];
                }
            }
            else {
                int step = 0;
                int j = i;
                while (j < len) {
                    ans += s[j];
                    step++;
                    if (step % 2 == 1) {
                        j += k - 2 * i;
                    }
                    else {
                        j += 2 * i;
                    }
                }
            }
        }
        return ans;
    }
};


int main()
{
    Solution solution;
    cout << solution.convert("A", 1);
}

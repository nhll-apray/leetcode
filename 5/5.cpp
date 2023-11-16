#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        /*int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        string maxStr = s.substr(0, 1);
        int maxl = 1;
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= n - l + 1; i++) {
                int j = i + l - 1;
                if (s[i] == s[j]) {
                    if (l == 2 || dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        if (j - i + 1 > maxl) {
                            maxl = j - i + 1;
                            maxStr = s.substr(i, maxl);
                        }
                    }
                }
            }
        }
        return maxStr;*/

        int n = s.size();
        int len;
        int maxl = 0;
        int beg = 0;
        for (int i = 0; i < n; i++) {
            len = centerLen(s, i, i);
            len = max(len, centerLen(s, i, i + 1));
            if (len > maxl) {
                maxl = len;
                beg = i - (len - 1) / 2;
            }
        }
        return s.substr(beg, maxl);
    }

    int centerLen(string& s, int i, int j) {
        int n = s.size();
        if (0 <= i && j < n && s[i] == s[j]) {
            return centerLen(s, i - 1, j + 1);
        }
        else {
            return (j - i - 1);
        }      
    }
};

int main()
{
    Solution solution;
    cout << solution.longestPalindrome("bb");
}


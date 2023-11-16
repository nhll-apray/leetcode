#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int len1 = s.size(), len2 = p.size();
        vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1));
        dp[0][0] = true;

        for (int i = 0; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (i >= 1 && (p[j - 1] == '.' || s[i - 1] == p[j - 1])) {
                    if (dp[i - 1][j - 1]) {
                        dp[i][j] = true;
                        continue;
                    }
                }
                if (p[j - 1] == '*' && j >= 2) {
                    if (dp[i][j - 2]) {
                        dp[i][j] = true;
                        continue;
                    }
                    if (i >= 1 && (p[j - 2] == '.' || p[j - 2] == s[i - 1])) {
                        if (dp[i - 1][j]) {
                            dp[i][j] = true;
                            continue;
                        }
                    }
                }
                dp[i][j] = false;
            }
        }

        /*for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }*/

        return dp[len1][len2];

    }
};

int main()
{
    Solution sol;
    string s = "ab";
    string p = "ab*";
    cout << sol.isMatch(s, p);
}


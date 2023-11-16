#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string btm[10] = { "", "", "abc", "def", "ghi",  "jkl",  "mno",  "pqrs",  "tuv",  "wxyz" };
    vector<string> letterCombinations(string digits) {
        if (digits == "") {
            return {};
        }
        vector<string> ans;
        buildStr(ans, digits, 0, "");
        return ans;
    }

    void buildStr(vector<string>& ans, string& digits, int t, string str) {
        if (t == digits.size()) {
            ans.push_back(str);
            return;
        }
        int a = digits[t] - '0';
        for (int i = 0; i < btm[a].size(); i++) {
            buildStr(ans, digits, t + 1, str + btm[a][i]);
        }
    }
};

int main()
{
    Solution sol;
    string str = "234";
    vector<string> ans = sol.letterCombinations(str);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}


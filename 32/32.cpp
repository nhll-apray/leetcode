#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        //int n = s.length();
        //if (n == 0) {
        //    return 0;
        //}
        //vector<int> dp(n);
        //int max = 0;
        //for (int i = 1; i < n; i++) {
        //    if (s[i] == '(') {
        //        dp[i] = 0;
        //    }
        //    else { // s[i] == ')'
        //        if (s[i - 1] == '(') {
        //            dp[i] = (i -2 >= 0 ? dp[i - 2] : 0) + 2;
        //        }
        //        else { // s[i - 1] == ')'
        //            if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
        //                dp[i] = (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0) + dp[i - 1] + 2;
        //            }
        //            else {
        //                dp[i] = 0;
        //            }
        //        }
        //    }
        //    if (dp[i] > max) {
        //        max = dp[i];
        //    }
        //}
        //return max;

        int n = s.length();
        stack<int> stack;
        stack.push(-1);
        int max = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                stack.push(i);
            }
            else { //if (s[i] == ')')
                stack.pop();
                if (stack.empty()) {
                    stack.push(i);
                }
                else {
                    int top = stack.top();
                    if (max < i - top) {
                        max = i - top;
                    }
                }
            }
        }
        return max;
    }
};

int main()
{
    Solution sol;
    string str = "(()())";
    cout << sol.longestValidParentheses(str);
}
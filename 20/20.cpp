#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        int n = s.size();
        if (n % 2 != 0) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
            case ')':
                if (!stack.empty() && stack.top() == '(') {
                    stack.pop();
                }
                else {
                    return false;
                }
                break;
            case ']':
                if (!stack.empty() && stack.top() == '[') {
                    stack.pop();
                }
                else {
                    return false;
                }
                break;
            case '}':
                if (!stack.empty() && stack.top() == '{') {
                    stack.pop();
                }
                else {
                    return false;
                }
                break;
            default:
                stack.push(s[i]);
            }
        }
        return stack.empty();
    }
};

int main()
{
    Solution sol;
    string s = "[";
    cout << sol.isValid(s);
}

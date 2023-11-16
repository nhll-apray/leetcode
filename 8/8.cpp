#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        bool neg = false;
        while (i < n && s[i] == ' ') {
            i++;
        }
        if (s[i] == '+') {
            neg = false;
            i++;
        }
        else if (s[i] == '-') {
            neg = true;
            i++;
        }
        int ans = 0;
        while (i < n && '0' <= s[i] && s[i] <= '9') {
            //cout << s[i] << endl;
            int a = s[i] - '0';
            if (!neg) {
                if (ans > INT_MAX / 10) {
                    return INT_MAX;
                }
                ans *= 10;
                if (ans > INT_MAX - a) {
                    return INT_MAX;
                }
                ans += a;
            }
            else {
                if (ans < INT_MIN / 10) {
                    return INT_MIN;
                }
                ans *= 10;
                if (ans < INT_MIN + a) {
                    return INT_MIN;
                }
                ans -= a;
            }
            i++;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string str = "                      -21474836488 3 with words";
    cout << sol.myAtoi(str);
}

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int n = 1;
        int m = 1;
        while (n <= x / 10) {
            n = n * 10;
            m++;
        }
        int left = x, right = x;
        for (int i = 1; i <= m / 2; i++) {
            int l = left / n;
            int r = right % 10;
            if (l != r) {
                return false;
            }
            left %= n;
            n /= 10;
            right /= 10;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    int x = 122222221;
    cout << sol.isPalindrome(x);
}

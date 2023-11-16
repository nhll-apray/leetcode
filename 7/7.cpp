#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    const int Max = (1 << 30) - 1 + (1 << 30);
    const int Min = -1 << 31;
    int reverse(int x) {
        bool neg = false; 
        int ans = 0, a;
        if (x < 0) {
            neg = true;
        }
        while (x != 0) {
            a = x % 10;
            x /= 10;
            if (!neg) {
                if (ans > Max / 10) {
                    return 0;
                }
                ans *= 10;
                if (ans > Max - a) {
                    return 0;
                }
                ans += a;
            }
            else {
                //cout << "neg" << endl;
                if (ans < Min / 10) {
                    return 0;
                }
                ans *= 10;
                if (ans < Min - a) {
                    return 0;
                }
                ans += a;
            }
        }

        /*for (int i = 0; i < v.size(); i++) {
            cout << v[i];
        }
        cout << endl;*/

        return ans;
    }
};

int main()
{
    Solution sol;
    int x = -2147483;
    cout << sol.reverse(x);
}


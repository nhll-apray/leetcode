#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN) {
            if (divisor == -1) {
                return INT_MAX;
            }
            if (divisor == 1) {
                return INT_MIN;
            }
        }
        if (dividend > 0) {
            return -divide(-dividend, divisor);
        }
        if (divisor > 0) {
            return -divide(dividend, -divisor);
        }
        if (dividend > divisor) {
            return 0;
        }
        int mul = divisor, quo = 1;
        while (dividend - mul < mul) {
            mul += mul;
            quo += quo;
        }
        return quo + divide(dividend - mul, divisor);
    }
};

int main()
{
    Solution sol;
    int dividend = -2147483648;
    int divisor = 2;
    cout << sol.divide(dividend, divisor);
}

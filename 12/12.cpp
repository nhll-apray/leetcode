#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string strN = to_string(num);
        int n = strN.size();
        string R[4][2] = { {"I", "V"}, {"X", "L"}, {"C", "D"}, {"M", ""} };
        string strR;
        for (int i = n - 1; i >= 0; i--) {
            switch (strN[n - 1 - i]) {
                case '1':
                    strR += R[i][0];
                    break;
                case '2':
                    strR += R[i][0] + R[i][0];
                    break;
                case '3':
                    strR += R[i][0] + R[i][0] + R[i][0];
                    break;
                case '4':
                    strR += R[i][0] + R[i][1];
                    break;
                case '5':
                    strR += R[i][1];
                    break;
                case '6':
                    strR += R[i][1] + R[i][0];
                    break;
                case '7':
                    strR += R[i][1] + R[i][0] + R[i][0];
                    break;
                case '8':
                    strR += R[i][1] + R[i][0] + R[i][0] + R[i][0];
                    break;
                case '9':
                    strR += R[i][0] + R[i + 1][0];
                    break;
            }
        }
        return strR;
    }
};

int main()
{
    Solution sol;
    int x = 58;
    cout << sol.intToRoman(x);
}

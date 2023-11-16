#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    //string map[4][10] = {
    //        {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
    //        {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
    //        {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
    //        {"", "M", "MM", "MMM", "#", "#", "#", "#", "#", "#"}
    //};
    //int romanToInt(string s) {
    //    int i = 0, j = 0, k = 3, a, index;
    //    int len = s.size();
    //    int m = 1000;
    //    int N = 0;
    //    //s += " ";
    //    while (i < len) {
    //        a = 0;
    //        string ss = "";
    //        while (j <= len && (index = find(ss, k)) >= 0) {
    //            a = index;
    //            ss += s[j];
    //            j++;
    //        }
    //        j--;
    //        N += a * m;
    //        i = j;
    //        k--;
    //        m /= 10;
    //    }
    //    return N;
    //}

    //int find(string s, int k) {
    //    for (int i = 0; i <= 9; i++) {
    //        if (s == map[k][i]) {
    //            return i;
    //        }
    //    }
    //    return -1;
    //}

    int romanToInt(string s) {
        map<char, int> map = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };

        int maxR = 0, N = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            int a = map[s[i]];
            if (a >= maxR) {
                N += a;
                maxR = a;
            }
            else {
                N -= a;
            }
        }
        return N;
    }

};

int main()
{
    Solution sol;
    string x = "MCMXCIV";
    cout << sol.romanToInt(x);
}


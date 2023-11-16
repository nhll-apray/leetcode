#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int i = -1, j = 0, maxl = 0;
        while (i < (int)s.length() && j < s.length()) {
            if (i >= 0) {
                set.erase(s[i]);
            }
            i++;
            while (j < s.length() && set.find(s[j]) == set.end()) {
                set.insert(s[j]);
                j++;
            }
            maxl = max(maxl, j - i);
        }
        return maxl;
    }
};



int main()
{
    Solution solution;
    string str = "12345";
    cout << solution.lengthOfLongestSubstring(str);

    return 0;

}


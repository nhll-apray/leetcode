#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int sLen = s.length();
        int m = words.size();
        int len = words[0].length();
        vector<int> ans;
        for (int i = 0; i < len; i++) {
            unordered_map<string, int> differ;
            int left = i;
            int right = i + (m - 1) * len;
            for (int j = left; j <= right; j += len) {
                string word = s.substr(j, len);
                differ[word]++;
            }
            for (auto& word : words) {
                if (--differ[word] == 0) {
                    differ.erase(word);
                }
            }
            if (differ.empty()) {
                ans.push_back(left);
            }
            while (right + len + len - 1 < sLen) {
                string word = s.substr(left, len);
                if (--differ[word] == 0) {
                    differ.erase(word);
                }
                left += len;
                right += len;
                word = s.substr(right, len);
                if (++differ[word] == 0) {
                    differ.erase(word);
                }
                if (differ.empty()) {
                    ans.push_back(left);
                }
            }
        }
        return ans;
    }
};

int main()
{
    string s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    vector<string> words = { "fooo","barr","wing","ding","wing" };
    Solution sol;
    vector<int> ans = sol.findSubstring(s, words);
    for (auto& element : ans) {
        cout << element << endl;
    }
}
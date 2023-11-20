#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void getNext(string str, vector<int>& nxt) {
        nxt.clear();
        nxt.push_back(0);
        int i = 0, j = 1;
        while (j < str.size()) {
            if (str[i] == str[j]) {
                nxt.push_back(i + 1);
                i++;
                j++;
            }
            else if (i > 0){
                i = nxt[i - 1];
            }
            else {
                nxt.push_back(0);
                j++;
            }
        }
    }
public:
    int strStr(string haystack, string needle) {
        vector<int> nxt;
        getNext(needle, nxt);
        for (int i = 0; i < nxt.size(); i++) {
            cout << nxt[i] << " ";
        }
        cout << endl;
        int i = 0, j = 0;
        while (j < haystack.size()) {
            if (haystack[j] == needle[i]) {
                if (i == needle.size() - 1) {
                    return j - i;
                }
                i++;
                j++;
            }
            else if (i > 0) {
                i = nxt[i - 1];
            }
            else {
                j++;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    string str = "abaababc";
    string ss = "ababc";
    cout << sol.strStr(str, ss);
}


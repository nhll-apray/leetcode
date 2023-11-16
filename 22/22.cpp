#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str = "";
        dfs(ans, str, 0, 0, n);
        return ans;
    }

    void dfs(vector<string>& ans, string& str, int l, int r, int& n) {
        if (l == n && r == n) {
            ans.push_back(str);
            return;
        }
        if (l < n) {
            str += '(';
            dfs(ans, str, l + 1, r, n);
            str.pop_back();
        }
        if (r < l) {
            str += ')';
            dfs(ans, str, l, r + 1, n);
            str.pop_back();
        }
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
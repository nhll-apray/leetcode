#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>>& ans, vector<int>& cur, vector<int>& candidates, int t, int target) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        for (int i = t; i < candidates.size(); i++) {
            int x = candidates[i];
            if (target >= x) {
                cur.push_back(x);
                dfs(ans, cur, candidates, i, target - x);
                cur.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> empty;
        dfs(ans, empty, candidates, 0, target);
        return ans;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
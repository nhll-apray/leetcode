#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>>& ans, vector<int>& cur, vector<int>& candidates, int t, int target) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        if (t >= candidates.size() || candidates[t] > target) {
            return;
        }
        int x = candidates[t];
        int k = t;
        while (k < candidates.size() && candidates[k] == x) {
            k++;
        }
        int num = k - t;
        for (int i = 0; i <= num; i++) {
            if (target >= i * x) {
                for (int j = 0; j < i; j++) {
                    cur.push_back(x);
                }
                dfs(ans, cur, candidates, k, target - i * x);
                for (int j = 0; j < i; j++) {
                    cur.pop_back();
                }
            }
            else {
                break;
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> empty;
        sort(candidates.begin(), candidates.end());
        dfs(ans, empty, candidates, 0, target);
        return ans;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}


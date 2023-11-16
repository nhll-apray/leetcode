#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j, k;
        int n1, n2, n3;
        while (i < n - 2 && nums[i] <= 0) {
            n1 = nums[i];
            j = i + 1;
            k = n - 1;
            while (j < k) {
                n2 = nums[j];
                n3 = nums[k];
                if (n1 + n2 + n3 == 0) {
                    ans.push_back({ n1, n2, n3 });
                    while (j < k && n2 == nums[j]) {
                        j++;
                    }
                    while (k > j && n3 == nums[k]) {
                        k--;
                    }
                }
                else if (n1 + n2 + n3 < 0) {
                    while (j < k && n2 == nums[j]) {
                        j++;
                    }
                }
                else {
                    while (k > j && n3 == nums[k]) {
                        k--;
                    }
                }
            }
            while (i < n - 2 && n1 == nums[i]) {
                i++;
            }

        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> v = { -1,0,1,2,-1,-4 };
    vector<vector<int>> ans = sol.threeSum(v);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < 3; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

}

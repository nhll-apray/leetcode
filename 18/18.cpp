#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j, k, h;
        int n1, n2, n3, n4;
        while (i < n - 3 && nums[i] / 1.0 * 4 <= target / 1.0) {
            n1 = nums[i];
            j = i + 1;
            while (j < n - 2 && n1 / 1.0 + 3.0 * nums[j] <= target / 1.0) {
                n2 = nums[j];
                k = j + 1;
                h = n - 1;
                while (k < h) {
                    n3 = nums[k];
                    n4 = nums[h];
                    if (n1 / 1.0 + n2 + n3 + n4 == target / 1.0) {
                        ans.push_back({ n1, n2, n3, n4 });
                        while (k < h && n3 == nums[k]) {
                            k++;
                        }
                        while (h > k && n4 == nums[h]) {
                            h--;
                        }
                    }
                    else if (n1 / 1.0 + n2 + n3 + n4 < target / 1.0) {
                        while (k < h && n3 == nums[k]) {
                            k++;
                        }
                    }
                    else {
                        while (h > k && n4 == nums[h]) {
                            h--;
                        }
                    }
                }
                while (j < n - 2 && n2 == nums[j]) {
                    j++;
                }
            }
            while (i < n - 3 && n1 == nums[i]) {
                i++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> v = { -3,-1,0,2,4,5 };
    vector<vector<int>> ans = sol.fourSum(v, 2);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < 4; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

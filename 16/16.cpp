#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int minD = 40000, ans;
        sort(nums.begin(), nums.end());
        int i = 0, j, k;
        int n1, n2, n3, cnt;
        while (i < n - 2 && nums[i] * 3 < target + minD) {
            n1 = nums[i];
            j = i + 1;
            k = n - 1;
            while (j < k) {
                n2 = nums[j];
                n3 = nums[k];
                cnt = n1 + n2 + n3;
                if (abs(cnt - target) < minD) {
                    minD = abs(cnt - target);
                    ans = cnt;
                }
                if (cnt < target) {
                    while (j < k && n2 == nums[j]) {
                        j++;
                    }
                }
                else if (cnt > target) {
                    while (k > j && n3 == nums[k]) {
                        k--;
                    }
                }
                else {
                    return target;
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
    vector<int> v = { 0, 0, 0 };
    int target = 1;
    cout << sol.threeSumClosest(v, target);
}

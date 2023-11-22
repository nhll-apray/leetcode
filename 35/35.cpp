#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] < target) {
                l = m + 1;
            }
            else if (nums[m] > target) {
                r = m - 1;
            }
            else {
                return m;
            }
        }
        return l;
    }
};

int main()
{
    Solution sol;
    vector<int> v = { 1,3,5,6 };
    int target = 0;
    cout << sol.searchInsert(v, target);
}


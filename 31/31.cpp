#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return;
        }
        int x = nums[n - 1];
        int i = n - 2;
        while (i >= 0 && nums[i] >= x) {
            x = nums[i];
            i--;
        }
        if (i == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int j = n - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 3};
    for (int i = 0; i < 6; i++) {
        sol.nextPermutation(nums);
        for (auto& element : nums) {
            cout << element << " ";
        }
        cout << endl;
    }
}

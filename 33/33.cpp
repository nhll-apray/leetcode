#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = nums.front(), right = nums.back();
        int l = 0, r = n - 1;
        while (l < r) {
            if (l + 1 == r) {
                l = nums[l] > nums[r] ? l : r;
                break;
            }
            int m = l + (r - l) / 2;
            if (nums[m] > left) {
                l = m;
            }
            else {
                r = m - 1;
            }
        }
        int k = n - 1 - l;
        l = 0;
        r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int newm = (m - k + n) % n;
            if (nums[newm] < target) {
                l = m + 1;
            }
            else if (nums[newm] > target) {
                r = m - 1;
            }
            else {
                return newm;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> v = { 4 };
    cout << sol.search(v, 3);
}

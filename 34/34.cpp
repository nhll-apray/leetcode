#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return { -1, -1 };
        }
        int l = 0, r = n - 1;
        int ansl = 0, ansr = 0;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] < target) {
                l = m + 1;
            }
            else {
                r = m - 1;
                ansl = m;
            }
        }
        if (nums[ansl] != target) {
            return { -1, -1 };
        }
        l = ansl;
        r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] <= target) {
                l = m + 1;
                ansr = m;
            }
            else {
                r = m - 1;
            }
        }
        return { ansl, ansr };
    }
};

int main()
{
    Solution sol;
    vector<int> v = { 2, 2 };
    int target = 3;
    cout << sol.searchRange(v, target)[0] << " " << sol.searchRange(v, target)[1];
}


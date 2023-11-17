#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k = 0, i = 0;
        while (i < n) {
            int x = nums[i];
            nums[k] = x;
            while (i < n && nums[i] == x) {
                i++;
            }
            k++;
        }    
        return k;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = { 1, 1, 2, 2, 3, 3, 4, 4, 4, 5 };
    int k = sol.removeDuplicates(nums);
    cout << k << endl;
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
}


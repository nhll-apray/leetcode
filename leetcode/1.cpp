#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            auto it = map.find(target - nums[i]);
            if (it == map.end()) {
                map[nums[i]] = i;
            }
            else {
                return { it->second, i };
            }
        }
        return {};
    }
};


int main()
{
    cout << "ss";
    Solution solution;
}


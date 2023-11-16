#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int maxV = 0;
        while (i < j) {
            int V = min(height[i], height[j]) * (j - i);
            //cout << V << endl;
            maxV = max(maxV, V);
            if (height[i] < height[j]) {
                i++;
            }
            else {
                j--;
            }
        }
        return maxV;
    }
};


int main()
{
    Solution sol;
    vector<int> v = { 1, 1 };
    cout << sol.maxArea(v);
}

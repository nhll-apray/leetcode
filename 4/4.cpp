#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if ((m + n) % 2 == 1) {
            return findK(nums1, nums2, (m + n + 1) / 2);
        }
        else {
            return (findK(nums1, nums2, (m + n) / 2) + findK(nums1, nums2, (m + n) / 2 + 1)) / 2.0;
        }
    }

    int findK(vector<int>& nums1, vector<int>& nums2, int k) {
        /*int m = nums1.size(), n = nums2.size();
        if (m == 0) {
            return nums2[k - 1];
        }
        if (n == 0) {
            return nums1[k - 1];
        }
        if (k == 1) {
            return min(nums1[0], nums2[0]);
        }

        int i1 = min(m, k / 2);
        int i2 = min(n, k / 2);
        if (nums1[i1 - 1] <= nums2[i2 - 1]) {          
            nums1.erase(nums1.begin(), nums1.begin() + i1);
            return findK(nums1, nums2, k - i1);
        }
        else {
            nums2.erase(nums2.begin(), nums2.begin() + i2);
            return findK(nums1, nums2, k - i2);
        }*/

        int m = nums1.size(), n = nums2.size();
        int i1 = 0, i2 = 0, j1, j2;
        while (true) {
            if (i1 >= m) {
                return nums2[i2 + k - 1];
            }
            if (i2 >= n) {
                return nums1[i1 + k - 1];
            }
            if (k == 1) {
                return min(nums1[i1], nums2[i2]);
            }
            j1 = min(i1 + k / 2 - 1, m - 1);
            j2 = min(i2 + k / 2 - 1, n - 1);
            if (nums1[j1] <= nums2[j2]) {
                k -= j1 + 1 - i1;
                i1 = j1 + 1;
            }
            else {
                k -= j2 + 1 - i2;
                i2 = j2 + 1;
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = { 2, 3, 4, 5, 6 };
    vector<int> nums2 = { 1 };
    cout << sol.findMedianSortedArrays(nums1, nums2);
}


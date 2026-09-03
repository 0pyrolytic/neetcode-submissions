#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& a = (nums1.size() <= nums2.size() ? nums1 : nums2);
        vector<int>& b = (nums1.size() <= nums2.size() ? nums2 : nums1);
        
        int total = a.size() + b.size();
        int half = total / 2;
        
        int left = 0, right = a.size() - 1;
        while (true) {
            int mida = left + (right - left) / 2; 
            if (right < left) mida = -1; 
            
            int midb = half - (mida + 1) - 1;
            
            int aLeft = (mida < 0 ? numeric_limits<int>::min() : a[mida]);
            int bLeft = (midb < 0 ? numeric_limits<int>::min() : b[midb]);
            int aRight = (mida + 1 >= a.size() ? numeric_limits<int>::max() : a[mida + 1]);
            int bRight = (midb + 1 >= b.size() ? numeric_limits<int>::max() : b[midb + 1]);

            if (aLeft <= bRight && bLeft <= aRight) {
                if (total % 2 == 1) {
                    return min(aRight, bRight);
                }
                return (double)(max(aLeft, bLeft) + min(aRight, bRight)) / 2.0;
            } 
            else if (aLeft > bRight) {
                right = mida - 1;
            } 
            else {
                left = mida + 1; 
            }
        }
    }
};

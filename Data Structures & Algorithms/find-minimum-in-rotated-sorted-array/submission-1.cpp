class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1, mid, minV = nums[0];

        while(left <= right){
            mid = left + (right - left) / 2;
            if(nums[right] >= nums[left]){
                return min(minV, nums[left]);
            }else{
                if(nums[mid] >= nums[left]){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
                minV = min(nums[mid], minV);
            }
        }

        return minV;
    }
};

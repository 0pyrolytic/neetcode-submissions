class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid = (left + right)/2;
        while(left <= right){
            if(target > nums[mid]){
                left = mid + 1;
                mid = (left + right)/2;
            }else if(target < nums[mid]){
                right = mid - 1;
                mid = (left + right)/2;
            }else{
                return mid;
            }
        }
        return -1;
    }
};

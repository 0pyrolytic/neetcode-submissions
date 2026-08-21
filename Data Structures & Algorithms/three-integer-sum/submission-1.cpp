class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int left, right;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++){
            if(i != 0 && nums[i] == nums[i - 1])continue;
            if(nums[i] > 0) break;

            left = i + 1, right = nums.size() - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0){
                    ans.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left - 1]){
                        left++;
                    }
                    while(left < right && nums[right] == nums[right + 1]){
                        right--;
                    }
                }
                if(nums[left] + nums[right] + nums[i] > 0){
                    right--;
                }else if(nums[left] + nums[right] + nums[i] < 0){
                    left++;
                }
            }
        }

        return ans;
    }
};

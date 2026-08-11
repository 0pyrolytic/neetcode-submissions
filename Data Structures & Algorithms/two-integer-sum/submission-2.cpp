class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>numNeeded;
        for(int i = 0; i < nums.size(); i++){
            if(numNeeded.contains(target - nums[i])) return vector<int>{numNeeded[target - nums[i]], i};
            numNeeded[nums[i]] = i;
        }

        return vector<int>{-1, -1};
    }
};
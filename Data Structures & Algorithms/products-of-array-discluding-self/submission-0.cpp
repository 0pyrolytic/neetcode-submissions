class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n, nums[0]);
        vector<int>postfix(n);
        postfix[n - 1] = nums[n - 1];

        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] * nums[i];
            postfix[n - 1 - i] = postfix[n - i] * nums[n - 1 - i];
        }

        vector<int>ans(n, postfix[1]);
        ans[n - 1] = prefix[n - 2];

        for(int i = 1; i < n - 1; i++){
            ans[i] = prefix[i - 1] * postfix[i + 1];
        }

        return ans;
    }
};

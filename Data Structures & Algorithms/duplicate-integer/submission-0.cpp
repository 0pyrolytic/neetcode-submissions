class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,bool>seen;
        for(int n : nums){
            if(seen[n] == true) return true;
            seen[n] = true;
        }
        return false;
    }
};
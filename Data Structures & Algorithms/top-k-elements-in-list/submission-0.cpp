class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>freqCount;
        for(int n : nums){
            freqCount[n]++;
        }

        vector<vector<int>>numWFreq(nums.size() + 1, vector<int>());
        for(auto & [num, count] : freqCount){
            numWFreq[count].push_back(num);
        }

        vector<int>ans;
        for(int i = nums.size(); i > 0; i--){
            if(k == 0) return ans;
            if(!numWFreq[i].empty()){
                ans.insert(ans.end(), numWFreq[i].begin(), numWFreq[i].end());
            }
            k -= numWFreq[i].size();
        }

        return ans;
    }
};

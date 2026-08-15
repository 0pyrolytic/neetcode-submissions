class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int best = 0;

        for (int num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int length = 1;
                int next = num + 1;
                while (numSet.find(next) != numSet.end()) {
                    next++;
                    length++;
                }
                best = max(best, length);
            }
        }
        return best;
    }
};

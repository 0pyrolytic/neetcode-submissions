class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, maxSize = 0;
        unordered_map<char, int>seenChar;
        while(r < s.size()){
            maxSize = max(maxSize, r - l + 1);
            seenChar[s[r]] = r;
            r++;
            if(r < s.size() && seenChar.contains(s[r])){
                while(l < (seenChar[s[r]] + 1)){
                    seenChar.erase(s[l]);
                    l++;
                }
            }
        }

        return maxSize;
    }
};

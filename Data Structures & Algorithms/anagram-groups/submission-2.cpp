class Solution {
public:
    struct VectorHash {
        size_t operator()(const vector<int>& v) const {
            size_t seed = v.size();
            for (int x : v) {
                seed ^= hash<int>{}(x) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<vector<int>, vector<string>, VectorHash> groups;
        groups.reserve(strs.size());

        for (string& s : strs) {
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            groups[count].push_back(s);
        }

        vector<vector<string>> result;
        result.reserve(groups.size());
        for (auto& [key, group] : groups) {
            result.push_back(move(group));
        }

        return result;
    }
};
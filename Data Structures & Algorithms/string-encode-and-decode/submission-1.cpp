class Solution {
public:
    string encode(vector<string>& strs) {
        string result;
        for (const string& s : strs) {
            result += to_string(s.size());
            result += '#';
            result += s;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        int n = s.size();

        while (i < n) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int len = stoi(s.substr(i, j - i));

            int start = j + 1;
            ans.push_back(s.substr(start, len));

            i = start + len;
        }

        return ans;
    }
};
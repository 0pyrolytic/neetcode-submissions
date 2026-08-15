class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> bracketMap{{'(', ')'}, {'{', '}'}, {'[', ']'}};
        stack<char> currStack;

        for (char c : s) {
            if (bracketMap.contains(c)) {
                currStack.push(c);
            } else {
                if (currStack.empty() || bracketMap[currStack.top()] != c) {
                    return false;
                }
                currStack.pop();
            }
        }

        return currStack.empty();
    }
};
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans(temperatures.size(), 0);
        stack<int>currStack;

        for(int i = 0; i < temperatures.size(); i++){
            while(!currStack.empty() && temperatures[currStack.top()] < temperatures[i]){
                ans[currStack.top()] = i - currStack.top();
                currStack.pop();
            }
            currStack.push(i);
        }

        return ans;
    }
};

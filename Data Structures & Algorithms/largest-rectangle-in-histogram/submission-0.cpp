class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>>currStack;
        int maxNum = 0;
        
        for(int i = 0; i < heights.size(); i++){
            int height = heights[i];
            pair<int,int>currPair;

            currPair = {i, height};
            
            while(!currStack.empty() && height < currStack.top().second){
                currPair = {currStack.top().first, height};
                maxNum = max(maxNum, (i - currStack.top().first) * currStack.top().second);
                currStack.pop();
            }

            currStack.push(currPair);
        }

        while(!currStack.empty()){
            maxNum = max(maxNum, ((int)heights.size() - currStack.top().first) * currStack.top().second);
            currStack.pop();
        }

        return maxNum;
    }
};

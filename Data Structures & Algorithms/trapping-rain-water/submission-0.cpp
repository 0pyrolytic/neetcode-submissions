class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>prefixIndex(height.size(), 0);
        vector<int>postfixIndex(height.size());
        postfixIndex[height.size() - 1] = height.size() - 1;
        int totalWater = 0;

        for(int i = 1; i < height.size() - 1; i++){
            if(height[i - 1] > height[prefixIndex[i - 1]]){
                prefixIndex[i] = i - 1;
            }else{
                prefixIndex[i] = prefixIndex[i - 1];
            }
            if(height[height.size() - i] > height[postfixIndex[height.size() - i]]){
                postfixIndex[height.size() - i - 1] = height.size() - i;
            }else{
                postfixIndex[height.size() - i - 1] = postfixIndex[height.size() - i];
            }
        }

        for(int i = 1; i < height.size() - 1; i++){
            int water = min(height[prefixIndex[i]], height[postfixIndex[i]]) - height[i];

            if(water > 0){
                totalWater += water;
            }
        }

        return totalWater;
    }
};

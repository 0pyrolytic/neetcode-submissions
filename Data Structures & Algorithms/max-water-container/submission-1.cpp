class Solution {
public:
    int maxArea(vector<int>& heights) {
        int right = heights.size() - 1, left = 0, maxWater = 0;

        while(left < right){
            maxWater = max(maxWater, min(heights[left], heights[right]) * (right - left));

            if(heights[left] < heights[right]){
                left++;
            }else{
                right--;
            }
        }

        return maxWater;
    }
};

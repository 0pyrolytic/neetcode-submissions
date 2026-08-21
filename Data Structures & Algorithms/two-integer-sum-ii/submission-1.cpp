class Solution { 
public: 
    vector<int> twoSum(vector<int>& numbers, int target) { 
        int needNum = 0, left = 0, right = numbers.size() - 1;
        
        while(left < right){             
            if(target - numbers[left] < numbers[right]){
                right--;
            }else if(target - numbers[left] > numbers[right]){
                left++;
            }else if(target - numbers[left] == numbers[right]){
                break;
            }
        } 
        
        return vector<int>{left + 1, right + 1}; 
    } 
};

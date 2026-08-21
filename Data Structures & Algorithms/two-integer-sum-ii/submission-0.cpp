class Solution { 
public: 
    vector<int> twoSum(vector<int>& numbers, int target) { 
        unordered_map<int, int> seenNum; 
        
        for(int i = 0; i < numbers.size(); i++){ 
            int n = numbers[i]; 
            
            if(seenNum.contains(target - n)){ 
                return vector<int>{seenNum[target - n], i + 1}; 
            } 
            seenNum[n] = i + 1; 
        } 
        
        return vector<int>{-1, -1}; 
    } 
};

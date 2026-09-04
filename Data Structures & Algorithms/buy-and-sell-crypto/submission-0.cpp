class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 100, largest = 0;

        for(int n : prices){
            if(n < left) left = n;
            else largest = max(largest, n - left);
        }

        return largest;
    }
};

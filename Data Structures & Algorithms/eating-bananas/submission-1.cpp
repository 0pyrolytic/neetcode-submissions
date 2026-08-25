class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = *max_element(piles.begin(), piles.end()), l = 1, m; //k bounds

        while(l <= r){
            m = l + (r - l) / 2;

            int timeL = h;
            for(double n : piles){
                timeL -= ceil(n / (double) m);
            }

            cout << m << " " << l << " " << r << " " << timeL << endl;
            //target == 0 (min integer will be closest positive to 0)
            if(timeL >= 0){
                r = m - 1;
            }else{
                l = m + 1;
            }
        }

        cout << m << " " << l << " " << r << " " << endl;
        return l;
    }
};

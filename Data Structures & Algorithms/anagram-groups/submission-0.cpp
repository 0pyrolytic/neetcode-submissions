class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int>vectorPos;
        vector<vector<string>>sortedAna;
        int currentPos = 0;

        for(string & s : strs){
            string sOrg = s;
            sort(s.begin(), s.end());
            if(vectorPos.contains(s)){
                sortedAna[vectorPos[s]].push_back(sOrg);
            }else{
                vectorPos[s] = currentPos;
                sortedAna.push_back(vector<string>{sOrg});                
                currentPos++;
            }
        }

        return sortedAna;
    }
};

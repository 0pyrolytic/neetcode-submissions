class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>>row(9);
        vector<unordered_set<int>>col(9);
        vector<unordered_set<int>>subBox(10);
        int colInc = 0, rowInc = 0;

        for(int k = 1; k <= 9; k++){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    int currentRow = j + rowInc, currentCol = i + colInc, currentNum = board[currentRow][currentCol];
                    if(subBox[k].contains(currentNum) || row[currentRow].contains(currentNum) || col[currentCol].contains(currentNum)){
                        return false;
                    }else{
                        if(currentNum != '.'){
                            subBox[k].insert(currentNum);
                            row[currentRow].insert(currentNum);
                            col[currentCol].insert(currentNum);
                        }
                    }
                }
            }
            if(k % 3 == 0){
                colInc += 3;
                rowInc = 0;
            }else{
                rowInc += 3;
            }
        }

        return true;
    }
};

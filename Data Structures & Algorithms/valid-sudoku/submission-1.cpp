class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowMask[9] = {0};
        int colMask[9] = {0};
        int boxMask[9] = {0};

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char ch = board[r][c];
                if (ch == '.') continue;

                int digit = ch - '1';
                int bit = 1 << digit;        
                int boxIdx = (r / 3) * 3 + (c / 3);

                if ((rowMask[r] & bit) || (colMask[c] & bit) || (boxMask[boxIdx] & bit)) {
                    return false;
                }

                rowMask[r] |= bit;
                colMask[c] |= bit;
                boxMask[boxIdx] |= bit;
            }
        }
        return true;
    }
};
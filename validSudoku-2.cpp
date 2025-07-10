class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int cols[9] = {0};
        int squares[9] = {0};

        for (int r = 0; r < board.size(); ++r)
        {
            for (int c = 0; c < board[0].size(); ++c)
            {
                char currStr = board[r][c];
                if (currStr == '.') continue;

                int curr = (1 << (currStr - '1'));
                int sqKey = (r / 3) * 3 + (c / 3);                
                if (rows[r] & curr || cols[c] & curr || squares[sqKey] & curr)
                {
                    return false;
                }

                rows[r] |= curr;
                cols[c] |= curr;
                squares[sqKey] |= curr;
            }
        }

        return true;
    }
};

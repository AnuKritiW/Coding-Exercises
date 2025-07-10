class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> rows;
        unordered_map<int, unordered_set<int>> cols;
        
        map<pair<int, int>, unordered_set<int>> squares;

        for (int r = 0; r < board.size(); ++r)
        {
            for (int c = 0; c < board[0].size(); ++c)
            {
                char currStr = board[r][c];
                if (currStr == '.') continue;

                int curr = currStr - '1';
                pair<int, int> sqKey = pair<int, int>((r / 3), (c / 3));                
                if (rows[r].count(curr) || cols[c].count(curr) || squares[sqKey].count(curr))
                {
                    return false;
                }

                rows[r].insert(curr);
                cols[c].insert(curr);
                squares[sqKey].insert(curr);
            }
        }

        return true;
    }
};

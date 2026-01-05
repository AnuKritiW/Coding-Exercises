class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> isFlipBoard(board.size(), vector<bool>(board[0].size(), true));

        for (int c = 0; c < board[0].size(); c++)
        {
            dfs(board, isFlipBoard, 0, c);
            dfs(board, isFlipBoard, (board.size() - 1), c);
        }

        for (int r = 0; r < board.size(); r++)
        {
            dfs(board, isFlipBoard, r, 0);
            dfs(board, isFlipBoard, r, (board[0].size() - 1));
        }

        for (int r = 0; r < board.size(); r++)
        {
            for (int c = 0; c < board[0].size(); c++)
            {
                if (board[r][c] == 'O' && isFlipBoard[r][c])
                {
                    board[r][c] = 'X';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, vector<vector<bool>>& isFlipBoard, int r, int c)
    {
        if (r < 0 || c < 0 ||
            r >= board.size() || c >= board[0].size() ||
            !isFlipBoard[r][c] || board[r][c] == 'X') return;

        isFlipBoard[r][c] = false;

        dfs(board, isFlipBoard, (r - 1), c); // top
        dfs(board, isFlipBoard, (r + 1), c); // bottom
        dfs(board, isFlipBoard, r, (c - 1)); // left
        dfs(board, isFlipBoard, r, (c + 1)); // right
    }
};

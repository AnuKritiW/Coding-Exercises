class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> visitedQ;

        for (int r = 0; r < grid.size(); r++)
        {
            for (int c = 0; c < grid[0].size(); c++)
            {
                if (grid[r][c] == 0)
                {
                    visitedQ.push({r, c});
                }
            }
        }

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!visitedQ.empty())
        {
            int r = visitedQ.front().first;
            int c = visitedQ.front().second;
            visitedQ.pop();

            for (int dirIdx = 0; dirIdx < directions.size(); dirIdx++)
            {
                int row = r + directions[dirIdx].first;
                int col = c + directions[dirIdx].second;

                if (row < 0 || col < 0 || 
                    row >= grid.size() || col >= grid[0].size() || 
                    grid[row][col] != INT_MAX) continue;

                grid[row][col] = grid[r][c] + 1;
                visitedQ.push({row, col});
            }
        }
    }
};

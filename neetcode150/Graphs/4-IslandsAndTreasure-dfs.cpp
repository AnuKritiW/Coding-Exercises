class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for (int r = 0; r < grid.size(); r++)
        {
            for (int c = 0; c < grid[0].size(); c++)
            {
                if (grid[r][c] == 0)
                {
                    dfs(grid, r, c, 0);
                    return;
                }
            }
        }
    }

    void dfs(vector<vector<int>>& grid, int r, int c, int neighbourValue) {
        if (r < 0 || c < 0 || r > (grid.size() - 1) || c > (grid[0].size() - 1)) return;

        if (grid[r][c] == -1) return;

        if (grid[r][c] == INT_MAX)
        {
            grid[r][c] = (neighbourValue + 1);
        }
        else if (grid[r][c] != 0) // it already has some value
        {
            int minPossible = min(grid[r][c], (neighbourValue + 1));
            if (grid[r][c] == minPossible) return;
            grid[r][c] = minPossible;
        }

        dfs(grid, r - 1, c, grid[r][c]); // top
        dfs(grid, r + 1, c, grid[r][c]); // bottom
        dfs(grid, r, c - 1, grid[r][c]); // left
        dfs(grid, r, c + 1, grid[r][c]); // right
    }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxIslandSize = 0;
        for (int r = 0; r < grid.size(); r++)
        {
            for (int c = 0; c < grid[0].size(); c++)
            {
                if (grid[r][c] == 0) continue;
                maxIslandSize = max(maxIslandSize, dfs(grid, r, c));
            }
        }

        return maxIslandSize;
    }

    int dfs(vector<vector<int>>& grid, int r, int c)
    {
        if (r < 0 || c < 0 || r >= grid.size() ||
            c >= grid[0].size() || grid[r][c] == 0) {
            return 0;
        }

        grid[r][c] = 0; // set curr cell to 0
        int res = 1;

        res += dfs(grid, r + 1, c); // bottom
        res += dfs(grid, r - 1, c); // top
        res += dfs(grid, r, c + 1); // right
        res += dfs(grid, r, c - 1); // left

        return res;
    }
};

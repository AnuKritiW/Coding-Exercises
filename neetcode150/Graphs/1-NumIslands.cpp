class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numIslands = 0;
        for (int r = 0; r < grid.size(); r++)
        {
            for (int c = 0; c < grid[0].size(); c++)
            {
                if (grid[r][c] == '0') continue;
                numIslands++;
                dfs(grid, r, c);
            }
        }

        return numIslands;
    }

    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        if (r < 0 || c < 0 || r > (grid.size() - 1) || c > (grid[0].size() - 1)) return;

        if (grid[r][c] == '1')
        {
            grid[r][c] = '0';
            dfs(grid, (r + 1), c);
            dfs(grid, (r - 1), c);
            dfs(grid, r, (c + 1));
            dfs(grid, r, (c - 1));
        }
    }
};

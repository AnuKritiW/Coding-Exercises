class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> pacific(heights.size(),  vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), false));

        for (int c = 0; c < heights[0].size(); c++)
        {
            dfs(heights, pacific, 0, c, 0);
            dfs(heights, atlantic, (heights.size() - 1), c, 0);
        }

        for (int r = 0; r < heights.size(); r++)
        {
            dfs(heights, pacific, r, 0, 0);
            dfs(heights, atlantic, r, (heights[0].size() - 1), 0);
        }

        vector<vector<int>> result;
        for (int r = 0; r < heights.size(); r++)
        {
            for (int c = 0; c < heights[0].size(); c++)
            {
                if (pacific[r][c] && atlantic[r][c])
                {
                    result.push_back({r, c});
                }
            }
        }

        return result;

    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c, int prevHeight)
    {
        if (r < 0 || c < 0 ||
            r >= heights.size() || c >= heights[0].size() ||
            visited[r][c] || heights[r][c] < prevHeight) return;

        visited[r][c] = true;

        dfs(heights, visited, (r - 1), c, heights[r][c]); // top
        dfs(heights, visited, (r + 1), c, heights[r][c]); // bottom
        dfs(heights, visited, r, (c - 1), heights[r][c]); // left
        dfs(heights, visited, r, (c + 1), heights[r][c]); // right
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        queue<pair<int, int>> rottenCoords;

        for (int r = 0; r < grid.size(); r++)
        {
            for (int c = 0; c < grid[0].size(); c++)
            {
                if (grid[r][c] == 1)
                {
                    fresh++;
                }
                if (grid[r][c] == 2)
                {
                    rottenCoords.push({r, c});
                    grid[r][c] = 0;
                }
            }
        }

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int numMinutes = 0;

        while (fresh > 0 && !rottenCoords.empty())
        {
            int rottenR = rottenCoords.front().first;
            int rottenC = rottenCoords.front().second;
            rottenCoords.pop();

            // for every direction from rotten fruit
            for (int dir = 0; dir < directions.size(); dir++)
            {
                int r = rottenR + directions[dir].first;
                int c = rottenC + directions[dir].second;

                if (r < 0 || c < 0 || 
                    r >= grid.size() || c >= grid[0].size() ||
                    grid[r][c] != 1) continue;
                
                grid[r][c] = grid[rottenR][rottenC] - 1;
                fresh--;
                numMinutes = max(numMinutes, abs(grid[r][c]));

                // push the newly rotten fruit into the queue
                rottenCoords.push({r, c});
            }
        }

        return (fresh == 0) ? numMinutes : -1;
    }
};

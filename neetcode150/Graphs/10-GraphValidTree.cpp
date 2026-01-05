class Solution {
    unordered_map<int, vector<int>> edgeMap;
    unordered_set<int> visited;
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < n; i++)
        {
            edgeMap[i] = {};
        }

        for (auto edge : edges)
        {
            edgeMap[edge[0]].push_back(edge[1]);
            edgeMap[edge[1]].push_back(edge[0]);
        }

        if (!dfs(0, -1)) return false;

        return (int)visited.size() == n;
    }

    bool dfs(int key, int prevKey)
    {
        visited.insert(key);
        for (int value : edgeMap[key])
        {
            if (value == prevKey) continue;

            auto foundIter = visited.find(value);
            // cycle found
            if (foundIter != visited.end()) return false;
            if (!dfs(value, key)) return false;
        }

        return true;
    }
};

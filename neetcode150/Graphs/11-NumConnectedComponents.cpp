class Solution {
    int components = 0;
    unordered_map<int, vector<int>> edgeMap;
    unordered_set<int> visited;
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        for (auto edge : edges)
        {
            edgeMap[edge[0]].push_back(edge[1]);
            edgeMap[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i++)
        {
            auto foundIter = visited.find(i);
            if (foundIter != visited.end()) continue;
            dfs(i, -1);
            components++;
        }

        return components;
    }

    void dfs(int node, int parent)
    {
        visited.insert(node);
        for (int neighbor : edgeMap[node])
        {
            if (neighbor == parent) continue;

            auto foundIter = visited.find(neighbor);
            if (foundIter != visited.end()) continue;

            dfs(neighbor, node);
        }
    }
};

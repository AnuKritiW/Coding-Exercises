class Solution {
    unordered_map<int, vector<int>> edgeMap;
    vector<bool> visited;
    unordered_set<int> cycle;
    int cycleStart = -1;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (auto edge : edges)
        {
            edgeMap[edge[0]].push_back(edge[1]);
            edgeMap[edge[1]].push_back(edge[0]);            
        }

        visited.resize((edges.size() + 1), false);
        dfs(1, -1);

        for (int i = edges.size() - 1; i >= 0; i--)
        {
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            if (cycle.count(node1) && cycle.count(node2))
            {
                return edges[i];
            }
        }

        return {};
    }

    bool dfs(int node, int parent)
    {
        if (visited[node])
        {
            // cycle detected; save the start point
            cycleStart = node;
            return true;
        }

        visited[node] = true;
        for (int nei : edgeMap[node])
        {
            if (nei == parent) continue;

            if (dfs(nei, node))
            {
                if (cycleStart != -1)
                {
                    // if we found a cycle in the dfs above, add curr node to the cycle
                    cycle.insert(node);
                }

                if (node == cycleStart)
                {
                    // we reached the end of the cycle
                    cycleStart = -1;
                }

                return true;
            }
        }

        return false;
    }
};

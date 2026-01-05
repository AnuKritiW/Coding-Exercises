class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        using intPair = pair<int, int>;
        unordered_map<int, vector<intPair>> srcToTgtMap;

        for (const auto& time : times)
        {
            intPair tgtTimePair({time[1], time[2]});
            srcToTgtMap[time[0]].push_back(tgtTimePair);
        }

        priority_queue<intPair, vector<intPair>, greater<>> minHeap;
        minHeap.push({0, k});

        set<int> visited;
        int minTime = 0;
        while (!minHeap.empty()) {
            auto curr = minHeap.top();
            minHeap.pop();
            
            int t1 = curr.first;
            int n1 = curr.second;

            if (visited.count(n1))
            {
                continue;
            }

            visited.insert(n1);
            minTime = t1;

            // if n1 has neighbors
            if (srcToTgtMap.count(n1))
            {
                // go through all n1's neigbors
                for (const auto& next : srcToTgtMap[n1])
                {
                    int n2 = next.first;
                    int t2 = next.second;

                    // if the neighbor has not been visited
                    if (!visited.count(n2))
                    {
                        // update the minHeap with the neighbor
                        minHeap.push({(t1+t2), n2});
                    }
                }
            }

        }

        return (visited.size() == n) ? minTime : -1;
    }
};

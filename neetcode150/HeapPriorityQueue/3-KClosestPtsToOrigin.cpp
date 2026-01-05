class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        struct Compare {
            static float getDist(const vector<int>& a)
            {
                return (a[0]*a[0] + a[1]*a[1]);
            }
            bool operator()(const vector<int>& a, const vector<int>& b) const {
                // Comparator for a max-heap by distance from origin
                // Returns true when `a` is LOWER priority than `b`
                // Farther points have higher priority, so `top()` is the farthest
                // This allows popping the farthest point when heap size exceeds k
                return getDist(a) < getDist(b);
            }
        };

        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        for (auto& point : points)
        {
            pq.push(point);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<vector<int>> result;
        while (!pq.empty())
        {
            result.push_back(pq.top());
            pq.pop();
        }

        return result;
    }
};

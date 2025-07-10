class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) {
            return 0;
        }
        
        sort(points.begin(), points.end(), 
             [](const vector<int> &o1, const vector<int> &o2) {
                 return (o1[1] < o2[1]);
             }
            );
        
        int arrows = 1;
        int curr_start, curr_end, first_end = points[0][1];
        
        for (auto p : points) {
            curr_start = p[0];
            curr_end = p[1];
            
            if (first_end < curr_start) {
                arrows++;
                first_end = curr_end;
            }
        }
        
        return arrows;
        
    }
};
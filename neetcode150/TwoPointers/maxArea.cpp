// Container With Most Water
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int largest = 0;

        while (l < r)
        {
            int leftHeight = heights[l];
            int rightHeight = heights[r];

            int area = min(leftHeight, rightHeight) * (r - l);
            largest = max(largest, area);

            (leftHeight < rightHeight) ? ++l : --r;
        }

        return largest;
    }
};

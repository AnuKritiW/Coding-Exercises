class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        int l = 0, r = height.size() - 1;
        int leftMax = height[l], rightMax = height[r];
        int result = 0;
        while (l < r)
        {
            int currWater = 0;
            if (leftMax < rightMax)
            {
                ++l;
                leftMax = max(leftMax, height[l]);
                result += leftMax - height[l];
            }
            else
            {
                --r;
                rightMax = max(rightMax, height[r]);
                result += rightMax - height[r];
            }
        }

        return result;
    }
};
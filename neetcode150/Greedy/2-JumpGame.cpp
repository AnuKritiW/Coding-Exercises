class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;

        int minStepSize = 1;
        for (int i = nums.size() - 2; i >=0 ; i--)
        {
            int currNum = nums[i];
            if (currNum >= minStepSize)
            {
                if (i == 0) return true;
                minStepSize = 1;
                continue;
            }
            minStepSize++;
        }
        return false;
    }
};

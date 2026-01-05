class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0]; // this is initialised to the first element because all the elements in nums may be negative
        int curSum = 0;

        for (int num : nums)
        {
            if (curSum < 0)
            {
                curSum = 0;
            }

            curSum += num;
            maxSum = max(maxSum, curSum);
        }

        return maxSum;
    }
};

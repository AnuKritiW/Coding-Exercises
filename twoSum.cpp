class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIndex;
        for (int i = 0; i < nums.size(); ++i)
        {
            int remaining = target - nums[i];
            if (numToIndex.find(remaining) != numToIndex.end())
            {
                return {numToIndex[remaining], i};
            }

            numToIndex.insert({nums[i], i});
        }
        return {};
    }
};

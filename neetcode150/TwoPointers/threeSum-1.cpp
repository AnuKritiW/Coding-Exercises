class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> result;

        for (int i = 0; i < nums.size(); ++i)
        {
            std::vector<int> slice(nums.begin() + i + 1, nums.begin() + nums.size());

            vector<vector<int>> twoSumRes = twoSum(slice, -nums[i]);

            if (!twoSumRes.empty())
            {
                for (auto& vec : twoSumRes)
                {
                    vector<int> triplet = {nums[i], vec[0], vec[1]};
                    sort(triplet.begin(), triplet.end());
                    result.insert(triplet);
                }
            }
        }

        std::vector<std::vector<int>> v(result.begin(), result.end());
        return v;
    }

    vector<vector<int>> twoSum(vector<int>& nums, int target)
    {
        vector<vector<int>> pairs;

        int l = 0;
        int r = nums.size() - 1;

        while (l < r)
        {
            if (nums[l] + nums[r] == target)
            {
                pairs.push_back({nums[l], nums[r]});
                l++;
                r--;
                continue;
            }
            (nums[l] + nums[r] > target) ? r-- : l++;
        }
        return pairs;
    }
};

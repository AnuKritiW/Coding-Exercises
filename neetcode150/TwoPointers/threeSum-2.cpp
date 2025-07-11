class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); ++i)
        {
            // skip duplicates
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int currNum = nums[i];

            int l = (i + 1);
            int r = nums.size() - 1;

            while (l < r)
            {
                int sum = nums[l] + nums[r] + currNum;
                if (sum == 0)
                {
                    result.push_back({currNum, nums[l], nums[r]});

                    while ((l < r) && nums[l] == nums[l + 1]) ++l;
                    while ((l < r) && nums[r] == nums[r - 1]) --r;

                    l++;
                    r--;
                    continue;
                }

                (sum > 0) ? r-- : l++;
            }

        }
        return result;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) return nums;

        int l = 0;
        
        int maxInWin = 0;
        int maxInWinIdx = 0;
        for (int i = 0; i < k; i++)
        {
            if (nums[i] > maxInWin)
            {
                maxInWin = nums[i];
                maxInWinIdx = i;
            }
        }

        vector<int> result = { maxInWin };

        for (int r = k; r < nums.size(); ++r)
        {
            l++;
            cout << "l: " << l << "; nums[l]: " << nums[l] << "; ";
            cout << "r: " << r << "; nums[r]: " << nums[r] << "\n";
            if (nums[r] > maxInWin)
            {
                maxInWin = nums[r];
                maxInWinIdx = r;
            }
            else
            {
                int removedIdx = r - k;
                if (removedIdx == maxInWinIdx)
                {
                    maxInWin = nums[l];
                    maxInWinIdx = l;
                    for (int i = l; i <= r; i++)
                    {
                        if (nums[i] > maxInWin)
                        {
                            maxInWin = nums[i];
                            maxInWinIdx = i;
                        }
                    }
                }
            }
            result.push_back(maxInWin);
        }

        return result;
    }
};

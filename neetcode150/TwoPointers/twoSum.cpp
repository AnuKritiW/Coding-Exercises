class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        sort(numbers.begin(), numbers.end());
        
        int l = 0;
        int r = (numbers.size() - 1);
        int maxR = r;

        while (l < r)
        {
            int currSum = numbers[l] + numbers[r];

            if (currSum == target)
            {
                return {l + 1, r + 1};
            }

            if (currSum > target)
            {
                r--;
            }
            else
            {
                l++;
            }    
        }

        return {};
    }
};

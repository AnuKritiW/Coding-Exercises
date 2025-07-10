class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet)
        {
            // if it is the smallest of a consecutive set
            if (numSet.find(num - 1) == numSet.end())
            {
                int length = 1;
                // while we can find the next consecutive number
                while (numSet.find(num + length) != numSet.end())
                {
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};

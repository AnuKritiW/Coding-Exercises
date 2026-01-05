class Solution {
public:
    int jump(vector<int>& nums) {
        int numJumps = 0;

        // range after each jump
        int l = 0;
        int r = 0;

        // the farthest index that can be reached from a given spot
        int farthest = 0;

        while (r < (nums.size() - 1))
        {
            for (int i = l; i <= r; i++)
            {
                farthest = max(farthest, i + nums[i]);
            }

            l = r + 1; // min steps from the right of the current jump range
            r = farthest;

            numJumps++;
        }

        return numJumps;
    }
};

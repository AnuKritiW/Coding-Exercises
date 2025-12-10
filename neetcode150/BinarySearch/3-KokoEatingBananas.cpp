class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int result = r;

        while (l<=r)
        {
            int k = (l + r)/2;
            int totalTime = 0;

            for (int pile : piles)
            {
                totalTime += (pile + k - 1) / k;
            }

            if (totalTime <= h)
            {
                result = k;
                r = k - 1;
            }
            else
            {
                l = k + 1;
            }
        }

        return result;

    }
};

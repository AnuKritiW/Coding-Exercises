class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1Size = nums1.size();
        int n2Size = nums2.size();

        if (n1Size > n2Size)
        {
            // check addressing
            vector<int> tmp = nums1;
            nums1 = nums2;
            nums2 = tmp;

            // refresh
            n1Size = nums1.size();
            n2Size = nums2.size();
        }

        // nums1 is always the shorter vector of the two arrays

        // set pointers for binary search
        int l = 0;
        int r = n1Size;

        int totalSize = (n1Size + n2Size);
        int half = (totalSize+1) / 2;

        while (l <= r)
        {
            int n1 = l + (r - l) / 2;
            // we have 'n1' elements to the left of n1

            int n2 = half - n1;

            int L1 = (n1 > 0)         ? nums1[n1-1] : INT_MIN;
            int R1 = (n1 < n1Size)    ? nums1[n1]   : INT_MAX;
            int L2 = (n2 > 0)         ? nums2[n2-1] : INT_MIN;
            int R2 = (n2 < n2Size)    ? nums2[n2]   : INT_MAX;

            if (L1 > R2)
            {
                r = n1 - 1;
                continue;
            }
            if (L2 > R1)
            {
                l = n1 + 1;
                continue;
            }
            
            if (totalSize % 2 == 0)
            {
                return (float(max(L1, L2)) + float(min(R1, R2))) / 2;
            }
            else
            {
                return max(L1, L2);
            }
        }
        return 0;
    }
};

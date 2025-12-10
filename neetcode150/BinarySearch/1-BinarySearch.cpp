class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        if ((target > nums[r]) || (target < nums[l])) return -1;

        while (l <= r)
        {
            cout << l;
            cout << r;
            if (nums[l] == target) return l;
            if (nums[r] == target) return r;
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) return mid;

            if (target > mid)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return -1;
    }
};

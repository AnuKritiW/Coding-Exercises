class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        productHelper(nums, result, 0, 1);
        return result;
    }

    // returns after product
    int productHelper(vector<int>& nums, vector<int>& result, int idx, int beforeProduct) {
        if (idx == nums.size()) return 1;

        int curr = nums[idx];
        int afterProduct = productHelper(nums, result, idx + 1, beforeProduct * curr);
        result[idx] = beforeProduct * afterProduct;
        return curr * afterProduct;
    }
};

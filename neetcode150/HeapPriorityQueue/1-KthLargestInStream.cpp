class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> nums;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums)
        {
            this->nums.push(num);
        }
        while (this->nums.size() > k)
        {
            this->nums.pop();
        }
    }

    int add(int val) {
        nums.push(val);
        while (nums.size() > k)
        {
            nums.pop();
        }
        return nums.top();
    }
};

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // if the number of cards is not a multiple of groupSize, return false
        if (hand.size() % groupSize != 0) return false;

        unordered_map<int, int> count;
        for (int num : hand) count[num]++;

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto& [key, _] : count) {
            minHeap.push(key);
        }

        while (!minHeap.empty())
        {
            while (!minHeap.empty() && count[minHeap.top()] == 0) {
                minHeap.pop();
            }
            if (minHeap.empty()) break;

            int start = minHeap.top();

            for (int i = start; i < (start + groupSize); i++)
            {
                // the group cannot be created
                if (count[i] <= 0) return false;
                
                // we remove it from the count as it becomes part of a group
                count[i]--;
            }
        }

        return true;

    }
};

// time n log m
// space n
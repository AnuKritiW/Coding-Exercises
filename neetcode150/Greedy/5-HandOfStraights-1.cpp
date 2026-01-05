class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // if the number of cards is not a multiple of groupSize, return false
        if (hand.size() % groupSize != 0) return false;

        unordered_map<int, int> count;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int num : hand)
        {
            count[num]++;
            minHeap.push(num);
        }

        while (!minHeap.empty())
        {
            int start = minHeap.top();
            minHeap.pop();

            if (count[start] <= 0) continue;

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

// time n log n
// space n

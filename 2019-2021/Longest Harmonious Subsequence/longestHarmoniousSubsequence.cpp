class Solution {
public:
    int findLHS(vector<int>& nums) {
        int max_count = 0;
        int count;
        std::map<int, int> map;
        int res = 0;
        for (int &num : nums) {
            map[num]++;
        }
        
        for(auto it = map.begin(); it != map.end(); it++) {
            int key=it->first;
            auto it_next = map.find(key+1); //find the next consecutive number
            if (it_next != map.end()) {
                count = it->second + it_next->second;
                max_count = std::max(max_count, count);
            }
        }
        return max_count;
        
    }
};
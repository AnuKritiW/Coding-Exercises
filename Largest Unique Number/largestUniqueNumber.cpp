class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        
        std::map<int, int> visited;
        int max_element = -1;
        
        for(const int &element:A) {
            visited[element]++;
        }
        
        int result = -1;
        for (auto &[key, val]:visited) {
            if (val==1) {
                result = max(result, key);
            }
        }
        return result;

    }
};
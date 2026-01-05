class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastIndex;
        for (int i = 0; i < s.size(); i++)
        {
            lastIndex[s[i]] = i;
        }

        vector<int> substringCounts;
        int currSubStrSize = 0;

        int start = 0;
        int end = 0;
        
        for (int i = 0; i < s.size(); i++)
        {
            end = max(end, lastIndex[s[i]]);
            if (i == end)
            {
                substringCounts.push_back(end - start + 1);
                start = i+1;
            }
        }

        return substringCounts;
    }
};

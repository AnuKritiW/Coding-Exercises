class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int len = 0; 
        // stores the char, and the last known index it appeared at
        unordered_map<char, int> charMap;

        for (int r = 0; r < s.size(); ++r)
        {
            if (charMap.find(s[r]) != charMap.end()) // if char in map
            {
                // check if the char that has been found is stale
                // i.e. was the last instance of the char in the current sliding window?
                if (charMap[s[r]] >= l)
                {
                    l = charMap[s[r]] + 1; // move the sliding window to the right by one
                }
            }
            charMap[s[r]] = r;
            len = max(len, r - l + 1);
        }
        return len;
    }
};

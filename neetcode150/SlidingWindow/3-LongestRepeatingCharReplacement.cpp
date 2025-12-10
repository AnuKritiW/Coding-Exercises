class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int len = 0;
        // within the sliding window, keeps track of the freq of each character
        unordered_map<int, int> countMap;
        int maxFreq = 0; // the number of the character that appears the most within the window
        
        for (int r = 0; r < s.size(); ++r)
        {
            countMap[s[r]]++;
            maxFreq = max(maxFreq, countMap[s[r]]);

            while (((r - l + 1) - maxFreq) > k)
            {
                // move left pointer to the right by one
                countMap[s[l]]--;
                l++;
            }

            int slidingWindowLen = (r - l + 1);
            len = max(len, slidingWindowLen);
        }

        return len;
    }
};

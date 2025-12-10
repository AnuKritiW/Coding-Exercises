class Solution {
public:
    string minWindow(string s, string t) {
        std::unordered_map<char, int> tMap;
        for (const auto& c : t)
        {
            tMap[c]++;
        }

        int missing = t.size();
        int l = 0;
        std::unordered_map<char, int> winMap;

        int bestLen = INT_MAX;
        int bestL = 0; 

        for (int r = 0; r < s.size(); ++r)
        {
            char& currChar = s[r];
            winMap[currChar]++;
            if (tMap.count(currChar))
            {
                if (winMap[currChar] <= tMap[currChar])
                {
                    missing--;
                }
            }

            while (missing == 0)
            {
                int currLen = (r - l + 1);
                if (currLen < bestLen)
                {
                    bestLen = currLen;
                    bestL = l;
                }
                
                winMap[s[l]]--;
                if (tMap.count(s[l]))
                {
                    if (winMap[s[l]] < tMap[s[l]])
                    {
                        missing++;
                    }
                }
                ++l;
            }
        }

        return bestLen == INT_MAX ? "" : s.substr(bestL, bestLen);
    }
};

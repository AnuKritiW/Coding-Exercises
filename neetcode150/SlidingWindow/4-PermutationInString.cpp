#include <array>

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const size_t s1Len = s1.size(), s2Len = s2.size();
        if (s1Len == 0) return true;
        if (s1Len > s2Len) return false;

        array<int,26> need{}, slidingWin{};
        for (char c : s1) need[c - 'a']++;

        for (size_t i = 0; i < s1Len; ++i) slidingWin[s2[i]- 'a']++;
        if (need == slidingWin) return true;

        for (size_t i = s1Len; i < s2Len; ++i)
        {
            slidingWin[s2[i] - 'a']++;
            slidingWin[s2[i - s1Len] - 'a']--;
            if (need == slidingWin) return true;
        }
        return false;
    }
};

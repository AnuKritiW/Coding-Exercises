class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mapToStr;

        for (const auto& s : strs) {
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }

            std::ostringstream oss;
            for (size_t i = 0; i < count.size(); ++i) {
                if (i != 0) oss << ",";
                oss << count[i];
            }

            string key = oss.str();
            mapToStr[key].push_back(s);
        }

        vector<vector<string>> result;
        for (const auto& pair : mapToStr) {
            result.push_back(pair.second);
        }

        return result;
    }
};

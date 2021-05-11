class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> currentList;
        dfs(result, s, 0, currentList);
        return result;
    }
    
    void dfs(vector<vector<string>> &result, string &s, int start, vector<string> &currentList) {
        if (start >= s.length()) result.push_back(currentList);
        
        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                currentList.push_back(s.substr(start, end - start + 1));
                //backtrack
                dfs(result, s, end+1, currentList);
                //remove substring from currentList
                currentList.pop_back();
            }
        }
        
    }
    
    bool isPalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    void backtrack(int openN, int closedN, int n, vector<string>& res, string& currStr)
    {
        if (openN == closedN && openN == n)
        {
            res.push_back(currStr);
        }

        if (openN < n)
        {
            currStr.push_back('(');
            backtrack(openN + 1, closedN, n, res, currStr);
            currStr.pop_back();
        }

        if (closedN < openN)
        {
            currStr.push_back(')');
            backtrack(openN, closedN + 1, n, res, currStr);
            currStr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string currStr;
        backtrack(0, 0, n, res, currStr);
        return res;
    }
};

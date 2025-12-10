class Solution {
public:
    int dfs(vector<string>& tokens) {
        const string& token = tokens.back();
        tokens.pop_back();

        if (token != "+" && token != "-" && token != "*" && token != "/")
        {
            return stoi(token);
        }

        int rhs = dfs(tokens);
        int lhs = dfs(tokens);

        if (token == "+") return lhs + rhs;
        else if (token == "-") return lhs - rhs;
        else if (token == "*") return lhs * rhs;
        else if (token == "/") return lhs / rhs;
    }

    int evalRPN(vector<string>& tokens) {
        return dfs(tokens);
    }
};

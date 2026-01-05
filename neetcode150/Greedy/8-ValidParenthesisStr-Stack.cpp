class Solution {
public:
    bool checkValidString(string s) {
        stack<int> openSt;
        stack<int> wildSt;

        for (int i = 0; i < s.size(); i++)
        {
            char currChar = s[i];

            if (currChar == '(')
            {
                openSt.push(i);
            }
            else if (currChar == ')')
            {
                if (openSt.empty())
                {
                    if (wildSt.empty()) return false;
                    wildSt.pop();
                    continue;
                }
                openSt.pop();
            }
            else if (currChar == '*')
            {
                wildSt.push(i);
            }
        }

        while (!openSt.empty())
        {
            if (wildSt.empty() || (wildSt.top() < openSt.top())) return false;
            openSt.pop();
            wildSt.pop();
        }

        return true;
    }
};

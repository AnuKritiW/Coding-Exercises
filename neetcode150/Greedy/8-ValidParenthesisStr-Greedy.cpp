class Solution {
public:
    bool checkValidString(string s) {
        int minUnmatchedOpen = 0;
        int maxUnmatchedOpen = 0;

        for (char c : s)
        {
            if (c == '(')
            {
                minUnmatchedOpen++;
                maxUnmatchedOpen++;
            }
            else if (c == ')')
            {
                minUnmatchedOpen--;
                maxUnmatchedOpen--;
            }
            else
            {
                minUnmatchedOpen--; // if * is ')'
                maxUnmatchedOpen++; // if * is '('
            }

            // more ')' than '(', even if we treat all previous '*' as '('
            if (maxUnmatchedOpen < 0) return false;

            if (minUnmatchedOpen < 0)
            {
                minUnmatchedOpen = 0;
            }
        }

        return (minUnmatchedOpen == 0);
    }
};

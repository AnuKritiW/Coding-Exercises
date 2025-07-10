class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedStr = "";
        for (auto& str : strs)
        {
            unsigned int strLen = str.size();
            encodedStr += to_string(strLen);
            encodedStr += '#';
            encodedStr += str;
        }

        return encodedStr;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;

        while (i < s.size())
        {
            int j = i;
            while (s[j] != '#')
            {
                ++j;
            }
            int strLen = stoi(s.substr(i, j-i));

            i = j + 1; // the first letter after '#'

            result.push_back(s.substr(i, strLen));
            i += strLen;
        }

        return result;
    }
};

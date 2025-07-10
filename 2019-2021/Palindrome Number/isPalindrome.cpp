class Solution {
public:
    bool isPalindrome(int x) {
        if ( (x < 0) || (x > 0 && x % 10 == 0) ){
            return false;
        }
        int i = x;
        int n = 0;
        while (i > 0) {
            if (n > INT_MAX/10 || n < INT_MIN/10){
                return false;
            }

            n = i % 10 + n * 10;

            i = i / 10;

        }

        return n == x;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);

        bool ret = Solution().isPalindrome(x);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}

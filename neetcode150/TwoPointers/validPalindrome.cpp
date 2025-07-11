class Solution {
public:
    bool isPalindrome(string s) {
        const char* front = s.c_str();
        const char* back = front + s.length() - 1;

        while (front < back) {
            while (front < back && !isalnum(*front)) ++front;
            while (front < back && !isalnum(*back)) --back;

            if (front >= back) break;

            if (tolower(*front) != tolower(*back)) return false;
            cout << *front << " " << *back << "\n";
            ++front;
            --back;
        }

        return true;
    }
};

class Solution:
    def isPalindrome(self, s: str) -> bool:
        alphanum_word = ""
        for char in s:
            if char.isalnum():
                alphanum_word = alphanum_word + char.lower()
        
        
        while(len(alphanum_word) > 0):
            if (alphanum_word[0] == alphanum_word[-1]):
                alphanum_word = alphanum_word[1:-1]
            else:
                return False
        
        return True
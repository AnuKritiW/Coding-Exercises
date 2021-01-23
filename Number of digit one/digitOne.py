class Solution:
    def countDigitOne(self, n: int) -> int:
        counter = 0
        i = 1
        while i <= n:
            divisor = i * 10
            counter += (n // divisor) * i + min(max(n % divisor - i + 1, 0), i)
            
            i *= 10
        
        return counter
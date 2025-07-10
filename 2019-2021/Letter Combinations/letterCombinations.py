class Solution(object):

    def DFS(self, digits, currentString, result):
        keypad = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        if not digits:
            result.append(''.join(currentString))
        else:
            digit = int(digits[0])
            for i in range(len(keypad[digit])):
                letter = keypad[digit][i]
                self.DFS(digits[1:], currentString+letter, result)
        return result

    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if not digits:
            return

        return self.DFS(digits, '', [])

def stringToString(input):
    return input[1:-1].decode('string_escape')

def stringArrayToString(input):
    return json.dumps(input)

def main():
    import sys
    def readlines():
        for line in sys.stdin:
            yield line.strip('\n')
    lines = readlines()
    while True:
        try:
            line = lines.next()
            digits = stringToString(line)

            ret = Solution().letterCombinations(digits)

            out = stringArrayToString(ret)
            print out
        except StopIteration:
            break

if __name__ == '__main__':
    main()

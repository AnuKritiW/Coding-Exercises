class Solution:
    def isValid(self, s: str) -> bool:
        bracketStack = []
        openBrackets = ['(', '[', '{']
        brackets = ['()', '[]', '{}']
        for x in s:
            if x in openBrackets:
                bracketStack.append(x)
            else:
                if not bracketStack or (bracketStack.pop() + x not in brackets):
                    return False
        return not bracketStack

def stringToString(input):
    import json

    return json.loads(input)

def main():
    import sys
    import io
    def readlines():
        for line in io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8'):
            yield line.strip('\n')

    lines = readlines()
    while True:
        try:
            line = next(lines)
            s = stringToString(line);

            ret = Solution().isValid(s)

            out = (ret);
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()

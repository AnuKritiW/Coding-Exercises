class Solution:
    def isHappy(self, n: int) -> bool:
        strNum = str(n)
        cycleDict = dict()
        while strNum != str(1):
            sum = 0
            for x in strNum:
                sum += pow(int(x), 2)
            if str(sum) in cycleDict:
                return False
            else:
                cycleDict[str(sum)] = True
            strNum = str(sum)
            # print(strNum)
        return True

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
            n = int(line);

            ret = Solution().isHappy(n)

            out = (ret);
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()

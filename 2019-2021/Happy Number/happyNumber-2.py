class Solution:
    def square(self, n):
        sqSum = 0
        while n > 0:
            ones = n % 10
            sqSum += ones ** 2
            n = n // 10
        return sqSum

    def isHappy(self, n: int) -> bool:
        if n == 1:
            return True
        sqSum = self.square(n)
        cycleDict = dict()

        while sqSum != 1:
            sqSum = self.square(sqSum)
            if sqSum not in cycleDict:
                cycleDict[sqSum] = True
            else:
                return False
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

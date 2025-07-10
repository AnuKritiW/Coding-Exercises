class Solution:
    def trap(self, height: List[int]) -> int:

        heightLength = len(height)
        if heightLength <= 2:
            return 0
        if heightLength == 3:
            return max(0, min(height[0], height[2]) - height[1])

        leftMax = list()
        maximum = 0
        for ht in height:
            leftMax.append(maximum)
            maximum = max(maximum, ht)

        rightMax = list()
        maximum = 0
        for ht in height[::-1]:
            rightMax.insert(0, maximum)
            maximum = max(maximum, ht)

        amtWater = 0
        for idx in range(heightLength):
            if idx == 0 or idx == heightLength - 1: #if at either extreme
                continue

            amtWater += max(0, min(leftMax[idx], rightMax[idx]) - height[idx])

        return amtWater

def stringToIntegerList(input):
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
            height = stringToIntegerList(line);

            ret = Solution().trap(height)

            out = str(ret);
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()

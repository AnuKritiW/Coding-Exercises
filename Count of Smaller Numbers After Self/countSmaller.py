class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:

        sortedNums = list()
        result = list()
        for idx in range(len(nums)-1, -1, -1):
            numSmaller = bisect.bisect_left(sortedNums, nums[idx])
            sortedNums.insert(numSmaller, nums[idx])
            result.append(numSmaller)
        return reversed(result)

def stringToIntegerList(input):
    return json.loads(input)

def integerListToString(nums, len_of_list=None):
    if not len_of_list:
        len_of_list = len(nums)
    return json.dumps(nums[:len_of_list])

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
            nums = stringToIntegerList(line);

            ret = Solution().countSmaller(nums)

            out = integerListToString(ret);
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()

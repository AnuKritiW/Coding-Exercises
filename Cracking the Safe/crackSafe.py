class Solution:
    def crackSafe(self, n: int, k: int) -> str:
        res = '0' * n
        visitedSet={res}

        for x in range(k**n):
            pre=res[len(res) - n + 1:]

            for y in range(k-1, -1, -1):
                cur = pre + str(y)

                if cur not in visitedSet:
                    visitedSet.add(cur)
                    res += str(y)
                    break

        return res

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
            line = next(lines)
            k = int(line);

            ret = Solution().crackSafe(n, k)

            out = (ret);
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()

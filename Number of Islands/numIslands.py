class Solution:
    def numIslands(self, grid):
        islandSt = []
        islandCount = 0
        for x in range(len(grid)):
            for y in range(len(grid[0])):
                if grid[x][y] == "1":
                    islandSt.append((x,y))
                    islandCount += 1
                    grid[x][y] = 'V'
                    if x+1 < len(grid) and grid[x+1][y] == "1":
                        islandSt.append((x+1, y))
                    if y+1 < len(grid[0]) and grid[x][y+1] == "1":
                        islandSt.append((x, y+1))

                while islandSt:
                    (i, j) = islandSt.pop()
                    grid[i][j] = 'V'

                    if i+1 < len(grid) and grid[i+1][j] == "1":
                        islandSt.append((i+1, j))
                    if j+1 < len(grid[0]) and grid[i][j+1] == "1":
                        islandSt.append((i, j+1))
                    if i-1 >= 0 and grid[i-1][j] == "1":
                        islandSt.append((i-1, j))
                    if j-1 >= 0 and grid[i][j-1] == "1":
                        islandSt.append((i, j-1))
        return islandCount

def stringToChar2dArray(input):
    return json.loads(input)

def intToString(input):
    if input is None:
        input = 0
    return str(input)

def main():
    import sys
    def readlines():
        for line in sys.stdin:
            yield line.strip('\n')
    lines = readlines()
    while True:
        try:
            line = lines.next()
            grid = stringToChar2dArray(line)

            ret = Solution().numIslands(grid)

            out = intToString(ret)
            print out
        except StopIteration:
            break

if __name__ == '__main__':
    main()

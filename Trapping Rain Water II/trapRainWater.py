class Solution(object):
    def trapRainWater(self, heightMap):
        """
        :type heightMap: List[List[int]]
        :rtype: int
        """
        if not heightMap or not heightMap[0]: #if no rows or no columns
            return 0

        rows = len(heightMap)
        columns = len(heightMap[0])

        heap = list()
        visited = set()

        for row in [0, rows - 1]:
            for col in range(columns):
                heap.append((heightMap[row][col], row, col))
                visited.add((row, col))

        for col in [0, columns-1]:
            for row in range(rows):
                if (row, col) in visited:
                    continue
                heap.append((heightMap[row][col], row, col))
                visited.add((row, col))
        # print(heap)
        heapq.heapify(heap)

        directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        result = 0

        while heap:
            # print(heap)
            ht, x, y = heapq.heappop(heap)
            for direction in directions:
                row, col = x + direction[0], y + direction[1]

                if not self.valid(rows, columns, row, col, visited):
                    continue

                tmp = ht - heightMap[row][col]
                if tmp > 0:
                    result += ht - heightMap[row][col]
                tmp = (max(ht, heightMap[row][col]), row, col)
                heapq.heappush(heap, tmp)
                visited.add((row, col))

        return result

    def valid(self, m, n, x, y, visited):
        return 0 <= x <= m - 1 and 0 <= y <= n - 1 and (x, y) not in visited

def stringToInt2dArray(input):
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
            heightMap = stringToInt2dArray(line)

            ret = Solution().trapRainWater(heightMap)

            out = intToString(ret)
            print out
        except StopIteration:
            break

if __name__ == '__main__':
    main()

#explanation taken rom discussion section
# Steps:
# 1. First we add all the surrounding to the building heights to a min_heap. Why?
#    Cuz we want to get the building that decides the level of the water that is held within
# 2. We pop from the min_heap, to get the least height building, this dictates how much water to add to result/ans
# 3. For each neighbour of the popped height we can get different in height and add that difference to the answer, as long as that is +ve
# 4. And then we push the (max(h, height of nbr), r, c), why? The max height dictates how much water will stay for (r, c) nbrs,
#    so if (r, c) is higher than the max so far, then that (r, c) will dictate how much it's nbrs can hold, so we pass the max along
# 5. Also, we use the visited array to keep track of all the visited co-ordinates and only visit unvisited nbrs

# Time: O(m * n log(m * n))
# Space: O(m * n)

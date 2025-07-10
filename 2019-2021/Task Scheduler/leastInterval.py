class Solution(object):
    def leastInterval(self, tasks, n):

        # n += 1

        taskDict = dict()
        for task in tasks:
            if task not in taskDict:
                taskDict[task] = 1
            else:
                taskDict[task] += 1

        numTasksWithMaxFreq = 0
        maxCount = 0
        remainingTasks = 0

        for task in taskDict:
            if taskDict[task] > maxCount:
                remainingTasks += (maxCount * numTasksWithMaxFreq)
                maxCount = taskDict[task]
                numTasksWithMaxFreq = 1
            elif taskDict[task] == maxCount:
                numTasksWithMaxFreq += 1
            else:
                remainingTasks += taskDict[task]

        if numTasksWithMaxFreq > n:
            return maxCount * numTasksWithMaxFreq + remainingTasks

        #remove the tasks which have been used to fill in the interval spaces
        remainingTasks -= (maxCount - 1) * (n + 1 - numTasksWithMaxFreq)

        if remainingTasks <= 0:
            return (maxCount - 1) * (n+1) + numTasksWithMaxFreq
        return (maxCount - 1) * (n+1) + numTasksWithMaxFreq + remainingTasks

def stringToCharArray(input):
    return json.loads(input)

def stringToInt(input):
    return int(input)

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
            tasks = stringToCharArray(line)
            line = lines.next()
            n = stringToInt(line)

            ret = Solution().leastInterval(tasks, n)

            out = intToString(ret)
            print out
        except StopIteration:
            break

if __name__ == '__main__':
    main()

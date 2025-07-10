class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0
        if (not coins) or (min(coins) > amount) or (len(coins)==1 and amount % coins[0] != 0):
            return -1

        dp = [amount+1]*(amount+1)
        dp[0] = 0

        for i in range(1, amount+1):
            for coin in coins:
                if coin <= i:
                    dp[i] = min(dp[i], 1 + dp[i-coin])
        if dp[amount] > amount:
            return -1
        else:
            return dp[amount]

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
            coins = stringToIntegerList(line);
            line = next(lines)
            amount = int(line);

            ret = Solution().coinChange(coins, amount)

            out = str(ret);
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()

class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        sum = 0
        hashmap = {}
        hashmap[0] = -1
        
        for i, num in enumerate(nums):
            sum += num
            if k != 0:
                sum = sum % k
            if sum in hashmap:
                if (i - hashmap[sum]) > 1:
                    return True
            else:
                hashmap[sum] = i
        return False
    

# (sum1 - sum2) % k = 0
# sum1 % k = sum2 % k
# basically add the modulo sums into the hasmap as you compute along the list
# as you are computing the modulo sums, check if the sum already exists in the hashmap.. if it does then you have a subarray matching the reqs

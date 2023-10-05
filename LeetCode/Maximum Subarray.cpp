class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        def kadane(i):
            if F[i] != None:
                return F[i]
            F[i] = max(nums[i],kadane(i-1) + nums[i])
            return F[i]
        n = len(nums)
        F = [None for _ in range(n)]
        F[0] = nums[0]
        kadane(n-1)
        return max(F)

## Kadane Algorithm

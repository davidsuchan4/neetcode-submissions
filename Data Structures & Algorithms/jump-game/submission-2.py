class Solution:
    def dfs(self, nums, position, dp):
        if position >= len(nums) - 1:
            return True
        if dp[position] != None:
            return dp[position]
        dist = nums[position]

        for i in range(1, dist + 1):
            if self.dfs(nums, position + i, dp):
                dp[position] = True
                return True
        dp[position] = False
        return False
    
    def canJump(self, nums: List[int]) -> bool:
        dp = [None] * len(nums)
        return self.dfs(nums, 0, dp)

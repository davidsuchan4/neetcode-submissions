class Solution:

    def dfs(self, curM, curN, m, n, dp):
        if curM == m - 1 and curN == n - 1:
            return 1
        
        if curM >= m or curN >= n:
            return 0
        
        if dp[curM][curN] != -1:
            return dp[curM][curN]
        
        dp[curM][curN] = self.dfs(curM + 1, curN, m, n, dp) + self.dfs(curM, curN + 1, m, n, dp)
        return dp[curM][curN]

    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[-1] * n for _ in range(m)]
        return self.dfs(0,0,m,n,dp)
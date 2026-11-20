class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        dp = {}

        def dfs(prices, idx, val, dp):
            if idx >= len(prices):
                return 0

            if (idx, val) in dp:
                return dp[(idx, val)]

            if val > -1:
                dp[(idx, val)] = max(
                    (prices[idx] - val) + dfs(prices, idx + 2, -1, dp),
                    dfs(prices, idx + 1, val, dp)
                )
            else:
                dp[(idx, val)] = max(
                    dfs(prices, idx + 1, val, dp),
                    dfs(prices, idx + 1, prices[idx], dp)
                )

            return dp[(idx, val)]

        return dfs(prices, 0, -1, dp)
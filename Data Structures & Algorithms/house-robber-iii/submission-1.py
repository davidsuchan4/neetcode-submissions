# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        dp = {}
        def dfs(root):
            if not root:
                return 0
            if root in dp:
                return dp[root]
            skip = dfs(root.left) + dfs(root.right)
            rob = root.val
            if root.right:
                rob += dfs(root.right.right) + dfs(root.right.left)
            if root.left:
                rob += dfs(root.left.left) + dfs(root.left.right)
            dp[root] = max(skip, rob)
            return dp[root]
        return dfs(root)
            

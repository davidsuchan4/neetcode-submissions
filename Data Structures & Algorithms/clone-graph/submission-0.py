"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""



class Solution:

    visited = set()

    def dfs(self, node):
        self.visited.add(node)
        if node: 
            for n in node.neighbors:
                if n in self.visited:
                    continue
                else:
                    self.visited.add(n)
                    self.dfs(n)
            return Node(node.val, node.neighbors)        


    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if node is None:
            return None
        
        clone = {}
        def dfs(original):
            if original in clone:
                return clone[original]
            
            clone[original] = Node(original.val)

            for node in original.neighbors:
                clone[original].neighbors.append(dfs(node))
            return clone[original]
        
        return dfs(node)

    
        
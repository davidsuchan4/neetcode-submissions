class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = max(max(a, b) for a, b in edges)
        redundant = []

        parent = list(range(n + 1))
        groupSize = group_size = [0] + [1] * n
        def root(node):
            while node != parent[node]:
                parent[node] = parent[parent[node]]
                node = parent[node]
            return node
        
        for edge in edges:
            a = root(edge[0])
            b = root(edge[1])

            if a == b:
                redundant.append(edge)
                continue
            
            if groupSize[a] < groupSize[b]:
                a,b = b, a
            
            parent[b] = a
            groupSize[a] += groupSize[b]
        return redundant[-1]
            

        
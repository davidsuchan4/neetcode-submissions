class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        heap = []
        parent = {tuple(point): tuple(point) for point in points}
        groupSize = {tuple(point): 1 for point in points}
        
        def find(node):
            while node != parent[node]:
                parent[node] = parent[parent[node]]
                node = parent[node]
            return node
        
        for i, start in enumerate(points):
            for end in points[i + 1:]:
                dist = abs(start[0] - end[0]) + abs(start[1] - end[1])
                heapq.heappush(heap, (dist, tuple(start), tuple(end)))
        
        visited = 0
        ret = 0

        while heap and visited < len(points):
            weight, start, end = heapq.heappop(heap)
            a = find(start)
            b = find(end)

            if a == b:
                continue
            
            if groupSize[a] < groupSize[b]:
                a,b = b,a
            
            parent[b] = a
            groupSize[a] += groupSize[b]
            visited += 1
            ret += weight
        return ret


        
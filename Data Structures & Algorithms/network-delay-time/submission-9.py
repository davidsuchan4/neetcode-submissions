class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        distance = {node: float("inf") for node in range(1, n + 1)}
        processed = set()
        distance[k] = 0
        maximum = 0

        for _ in range(n):
            u = None

            for v in range(1, n + 1):
                if v not in processed and (u is None or distance[v] < distance[u]):
                    u = v
            
            if u == None or distance[u] == float("inf"):
                break
            processed.add(u)
            for edge in times:
                source, dest, weight = edge
                if source != u:
                    continue
                candidate = distance[u] + weight
                if candidate < distance[dest]:
                    distance[dest] = candidate

        maximum = max(distance.values())
        return -1 if maximum == float("inf") else maximum

        
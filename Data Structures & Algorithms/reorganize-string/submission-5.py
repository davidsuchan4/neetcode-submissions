class Solution:
    def reorganizeString(self, s: str) -> str:
        freq = {}
        for char in s:
            freq[char] = freq.get(char, 0) + 1        
        maxheap = []
        
        for char in freq:
            heapq.heappush_max(maxheap, [freq[char], char])
        if maxheap[0][0] > (len(s) + 1) / 2:
            return ""
        ret = ""
        while len(maxheap) > 0:
            top = heapq.heappop_max(maxheap)
            
            ret += top[1]
            
            top[0] -= 1

            if len(maxheap) > 0:
                    second = heapq.heappop_max(maxheap)
                    ret += second[1]
                    second[0] -= 1
                    if second[0] > 0:
                        heapq.heappush_max(maxheap, second)

            if top[0] > 0:
                heapq.heappush_max(maxheap, top)
        return ret

        
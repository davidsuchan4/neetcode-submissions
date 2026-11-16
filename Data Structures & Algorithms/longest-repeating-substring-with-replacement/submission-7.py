class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        freq = {}
        p1 = 0
        p2 = 0
        maximum = 0
        most_freq = 0
        while p2 < len(s):
            first = s[p1]
            last = s[p2]
            if last not in freq:
                freq[last] = 1
            else:
                freq[last] += 1
            
            most_freq = max(most_freq, freq[last])
            
            while k < p2 - p1 + 1 - most_freq:
                freq[s[p1]] -= 1
                p1 += 1
            maximum = max(maximum, p2 - p1 + 1)
            p2 += 1
        return maximum
            

            
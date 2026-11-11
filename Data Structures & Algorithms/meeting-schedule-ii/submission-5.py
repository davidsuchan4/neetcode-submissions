"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        heap = []
        maximum = 0
        intervals.sort(key=lambda interval: interval.start)       
        time = 0
        for interval in intervals:
            time = interval.start
            heapq.heappush(heap, interval.end)
            while heap[0] <= time:
                heapq.heappop(heap)
            maximum = max(maximum, len(heap))
        return maximum

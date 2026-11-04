class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        queue = deque();
        car = 0
        destination = 0
        trips.sort(key=lambda trip: trip[2])

        for trip in trips:
            if trip[1] < destination:
                car += trip[0]
            else:
                car = trip[0]
            destination = trip[2]
            if car > capacity:
                return False

        return True

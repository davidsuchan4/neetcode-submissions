class StockSpanner:

    def __init__(self):
        self.prices = []

    def next(self, price: int) -> int:
        self.prices.append(price);
        span = 0
        for cur in reversed(self.prices):
            if price < cur:
                return span
            span += 1
        return span



        


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
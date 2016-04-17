class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0

        self.maxProfit = 0
        self.maxSellOut = prices[0]
        self.minBuyIn = prices[0]

        for price in prices:
            if price < self.maxSellOut:
                self.maxProfit += self.maxSellOut - self.minBuyIn
                self.minBuyIn = price
                self.maxSellOut = price
            elif price >= self.maxSellOut:
                self.maxSellOut = price
            elif price <= self.minBuyIn:
                self.minBuyIn = price

        if self.maxSellOut - self.minBuyIn > 0:
            self.maxProfit += self.maxSellOut - self.minBuyIn
        return self.maxProfit

s = Solution()
r = s.maxProfit([1,3,2,4,3,5])
print(r)

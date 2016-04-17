class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0
        self.maxProfit = 0
        self.minBuyIn = prices[0]
        for price in prices:
            if price - self.minBuyIn > self.maxProfit:
                self.maxProfit = price - self.minBuyIn
            elif price - self.minBuyIn < 0:
                self.minBuyIn = price
        return self.maxProfit


s = Solution()
r = s.maxProfit([4,40,30,1,500])
print(r)

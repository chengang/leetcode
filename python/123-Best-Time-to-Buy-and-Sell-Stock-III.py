class Solution(object):
    def maxProfit(self, prices):
        if not prices or len(prices) < 2:
            return 0

        firstProfit = []
        profit = 0
        minBuyIn = prices[0]

        for price in prices:
            if price < minBuyIn:
                minBuyIn = price
            elif price - minBuyIn > profit:
                profit = price - minBuyIn
            firstProfit.append(profit)

        prices.reverse()
        lastProfit = []
        maxProfit = profit
        profit = 0
        maxSellOut = prices[0]
        for price in prices:
            if price > maxSellOut:
                maxSellOut = price
            elif maxSellOut - price > profit:
                profit = maxSellOut - price
            lastProfit.insert(0, profit)

        print firstProfit
        print lastProfit

        for i in range(0, len(prices)):
            if firstProfit[i] + lastProfit[i] > maxProfit:
                maxProfit = firstProfit[i] + lastProfit[i]
        return maxProfit


s = Solution()
r = s.maxProfit([4,40,30,1,500])
#r = s.maxProfit([2,1])
print(r)

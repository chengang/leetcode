class Solution(object):
    
    def __init__(self):
        self.S = dict()

    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        self.S[1] = 1
        self.S[2] = 2
        for i in range(3, n+1):
            self.S[i] = self.S[i-1] + self.S[i-2]
            print (i, end='')
            print ("=>", end = "")
            print (self.S[i])
        return self.S[n]

solution = Solution()
result = solution.climbStairs(16)
print (result)

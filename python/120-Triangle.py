class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        w = len(triangle[-1])
        h = len(triangle)
        T = [[None for i in range(w)] for j in range(h)]
        for i in range(h):
            for j in range(i+1):
                if i - 1 < 0:
                    T[i][j] = triangle[i][j]
                else:
                    if T[i-1][j] == None:
                        T[i][j] = triangle[i][j] + T[i-1][j-1]
                    elif T[i-1][j-1] == None:
                        T[i][j] = triangle[i][j] + T[i-1][j]
                    else:
                        if T[i-1][j-1] < T[i-1][j]:
                            T[i][j] = triangle[i][j] + T[i-1][j-1]
                        else:
                            T[i][j] = triangle[i][j] + T[i-1][j]
            print(T)
        totalMin = T[-1][0]
        for i in range(len(T[-1])):
            if T[-1][i] < totalMin:
                totalMin = T[-1][i]
        return totalMin
        

s = Solution()
#r = s.minimumTotal([[2],[3,4],[6,5,7],[4,1,8,3]])
r = s.minimumTotal([[-8],[3,-6],[5,7,1],[-9,5,0,-4],[-2,4,-1,1,8]])
print(r)

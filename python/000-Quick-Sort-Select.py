class Solution(object):
    def partition(self, array, start, end):
        x = array[end]
        ptr = start
        for i in range(start, end):
            if array[i] < x:
                tmp = array[ptr]
                array[ptr] = array[i]
                array[i] = tmp
                ptr += 1

        tmp = array[end]
        array[end] = array[ptr]
        array[ptr] = array[end]
        return ptr

    def quickSelect(self, array, start, end, k):
        pos = self.partition(array, start, end)
        print(array[pos])
        if pos == k:
            return array[pos]
        else:
            if k < pos:
                r = self.quickSelect(array, start, pos-1, k)
            else:
                r = self.quickSelect(array, pos+1, end, k)
        if r:
            return r
        return 0


    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if k > len(nums):
            return 0
        k = k - 1
        return self.quickSelect(nums, 0, len(nums)-1, k)
        

s = Solution()
#r = s.findKthLargest([543,1231,34,43,234,56,1,3,4,5,2,78,34,4,1,5,7] , 8)
#r = s.findKthLargest([1,2,3,4,5,6,7,8,9,10,11,12,13] , 3)
r = s.findKthLargest([1], 1)
print(r)

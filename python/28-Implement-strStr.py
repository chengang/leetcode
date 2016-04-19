class Solution(object):
    # Rabin-Karp Algorthm
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        haystack_length = len(haystack)
        needle_length = len(needle)
        if haystack_length < needle_length:
            return -1

        needle_hash = 0
        haystack_hash = 0
        for c in range(needle_length):
            needle_hash = needle_hash + ord(needle[c])
            haystack_hash = haystack_hash + ord(haystack[c])

        if haystack_hash == needle_hash and haystack[:needle_length] == needle:
            return 0

        for i in range(0, haystack_length - needle_length):
            haystack_hash = haystack_hash - ord(haystack[i]) + ord(haystack[i+needle_length])
            if needle_hash == haystack_hash: 
                if haystack[i+1:i+1+needle_length] == needle:
                    return(i + 1)

        return -1
        
s = Solution()
pos = s.strStr("mississippi","pi")
print(pos)

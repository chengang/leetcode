class Solution(object):
    # Knuth-Morris-Pratt Algorthm
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if not haystack and not needle:
            return 0
        if not haystack:
            return -1
        if not needle:
            return 0

        needle_index = 0
        haystack_index = 0
        needle_length = len(needle)
        haystack_length = len(haystack)


        seek_table = dict()
        seek_table[0] = -1
        seek_index_test = 0
        seek_index_patten = -1
        while seek_index_test < needle_length:
            if seek_index_patten == -1 or needle[seek_index_test] == needle[seek_index_patten]:
                seek_table[seek_index_test] = seek_index_patten + 1
                seek_index_test += 1
                seek_index_patten += 1
            else:
                seek_index_patten = seek_table[seek_index_patten] - 1

        while haystack_index < haystack_length:
            if haystack[haystack_index] == needle[needle_index]:
                if needle_index == needle_length - 1:
                    return haystack_index - needle_index
                else:
                    haystack_index += 1
                    needle_index += 1
            else:
                if needle_index == 0: 
                    haystack_index += 1
                elif seek_table[needle_index] == -1:
                    needle_index = 0
                else:
                    needle_index = seek_table[needle_index-1]

        return -1
        
s = Solution()
#pos = s.strStr("mississippi","pi1231231pi231")
#pos = s.strStr("bbbbababbbaabbba","abb")
#pos = s.strStr("mississippi","issip")
pos = s.strStr("abaaa","abb")
print(pos)

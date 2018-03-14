class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        Length = 0
        LongestStr = ""
        for i in range(0, len(s)):
            k = 0
            #回文序列的长度可能是奇数，也可能是偶数
            while i-k >=0 and i+k < len(s) and s[i-k] == s[i+k]:
                k += 1
            if k * 2 - 1 > Length:
                Length = k * 2 - 1
                LongestStr = s[i-k+1:i+k]
                #print Length, LongestStr
                
            k = 0
            while i-k-1 >=0 and i+k < len(s) and s[i-k-1] == s[i+k]:
                k += 1
            if k * 2 > Length:
                Length = k * 2
                LongestStr = s[i-k:i+k]
                #print Length, LongestStr
        #print Length, LongestStr
        return LongestStr
                
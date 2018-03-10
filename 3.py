class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        maxLength = 0
        curLength = 0
        strBuf = ""
        for i in range(0, len(s)):
            if s[i] not in strBuf:
                strBuf += s[i]
                curLength += 1
            else:
                index = strBuf.find(s[i])
                strBuf = strBuf[index+1:]
                strBuf += s[i]
                curLength = len(strBuf)
            if curLength > maxLength:
                maxLength = curLength
        return maxLength
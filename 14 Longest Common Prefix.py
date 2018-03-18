class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) >= 1:
            prefix = strs[0]
        else:
            return ""

        for item in strs[1:]:
            while True:
                length = len(prefix)
                if prefix == item[:length]:
                    break
                else:
                    prefix = prefix[:length-1]
        return prefix
if __name__ == "__main__":
    a = 'a'
    print (a[:0] == "")

    S = Solution()
    #print (S.longestCommonPrefix(['abccdef', "abcde", "abccd"]))
    print (S.longestCommonPrefix(['']))
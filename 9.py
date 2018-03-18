class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        strNum = str(x)
        #负数肯定不是回文序列
        if strNum[0] == '-':
            return False
        i = 0
        length = len(strNum)
        while i < length - 1 - i:
            if strNum[i] != strNum[length-1-i]:
                return False
            i += 1
            #print (i)
        return True
        
if __name__ == '__main__':
    x = int(input())
    s = Solution()    
    print (s.isPalindrome(x))

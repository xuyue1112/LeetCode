class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        thousands = ["", "M", "MM", "MMM"]
        hundred = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
        tens = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
        ones = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]
        number = 0
        for i in range(3,-1,-1):
            length = len(thousands[i])
            if s[0:length] == thousands[i]:
                number += i*1000
                s = s[length:]
                break
        for i in range(9, -1, -1):
            length = len(hundred[i])
            if s[0:length] == hundred[i]:
                number += i * 100
                s = s[length:]
                break
        for i in range(9, -1, -1):
            length = len(tens[i])
            if s[0:length] == tens[i]:
                number += i * 10
                s = s[length:]
                break
        for i in range(9, -1, -1):
            length = len(ones[i])
            if s[0:length] == ones[i]:
                number += i * 1
                s = s[length:]

        return number

if __name__ == "__main__":
    S = Solution()
    print (S.romanToInt("MMMCMXCIX"))
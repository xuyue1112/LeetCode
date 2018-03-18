# 像这种只有有限中情况，可以罗列出来的题，不妨把所有情况都列出来。而不是写很多if-else语句

class Solution:
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        thousands = ["", "M", "MM", "MMM"]
        hundred = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
        tens = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
        ones = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]
        return thousands[num//1000] + hundred[(num%1000)//100] + tens[(num%100)//10] + ones[(num%10)]

if __name__ == "__main__":
    S = Solution()
    print (S.intToRoman(3999))
class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        INT_MAX = '2147483647'
        INT_MIN = '2147483648'
        str = iter(str)
        while True:
            try:
                chr = next(str)
            except StopIteration:
                return 0
            if not ( chr == ' ' or chr == '\t' or chr == '\n' ):
                break
        strNum = ""
        count = 0
        plus_minus = 0 # 0:正数 ； 1：负数
       
        #循环中，应该多读了一个字符，所以这里不用读了
        if chr >= '0' and chr <= '9':
            strNum += chr
            count += 1
        elif chr == '-':
            plus_minus = 1
        elif chr == '+':
            plus_minus = 0
        else:
            return 0

        while True:
            try:
                chr = next(str)
            except StopIteration:
                break
            if chr >= '0' and chr <= '9':
                strNum += chr
                count += 1
                if count == 10:
                    #判断当前数值是否越界
                    for i in range(count):
                        if plus_minus == 0 and strNum[i] > INT_MAX[i]:
                            return self.strToInt(INT_MAX)
                        elif plus_minus == 1 and strNum[i] > INT_MIN[i]:
                            return self.strToInt('-' + INT_MIN)
                        if plus_minus == 0 and strNum[i] < INT_MAX[i] or plus_minus == 1 and strNum[i] < INT_MIN[i]:
                            break
                if count > 10:
                    if plus_minus == 0:
                        return self.strToInt(INT_MAX)
                    elif plus_minus == 1:
                        return self.strToInt('-' + INT_MIN)

            else:
                break
        if len(strNum) == 0:
            return 0
        if plus_minus == 1:
            strNum = '-' + strNum
        return self.strToInt(strNum)
    def strToInt(self, str):
        plus_minus = 0
        if str[0] == '-':
            plus_minus = 1
            str = str[1:]
        intNum = 0
        for chr in str:
            intNum = intNum * 10 + int(chr)
        if plus_minus == 1:
            intNum = -1 * intNum
        return intNum
if __name__ == "__main__":
    str = input()
    s = Solution()
    print(s.myAtoi(str))
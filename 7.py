class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        x = list(str(x))
        plus_minus =  1
        if x[0] == '-':
            plus_minus = -1
            x = x[1:]
        maxInt = "2147483647"
        minInt = "2147483648"
        x.reverse()
        while x[0] == 0:
            x = x[1:]
        if len(x) > len(maxInt): #如果数字的长度大于maxInt的长度，说明用int32存储不了，直接返回了
            return 0 
        elif len(x) == len(maxInt): #如果长度相同，那就逐位比较大小。如果出现对应数位前者大于后者的情况，直接返回；如果小于，退出循环；如果等于，继续循环
            for i in range(0, len(x)):
                if plus_minus == 1 and int(x[i]) > int(maxInt[i]) or plus_minus == -1 and int(x[i]) > int(minInt[i]):
                    return 0 
                elif plus_minus == 1 and int(x[i]) < int(maxInt[i]) or plus_minus == -1 and int(x[i]) < int(minInt[i]):
                    break
        result = ""
        if plus_minus == -1:
            result += "-"
        result += "".join(x)
        return int(result)
        
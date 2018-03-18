class Solution:
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        s = iter(s)
        regExpList = []
        p = iter(p)
        curFigure = []
        try:
            chr = next(p)
            curFigure.append(chr)
        except StopIteration:
            print ("Regular Expression is Empty.")
        # 构建一个数据结构regExpList (type : list)。每一个元素是(chr, number) 即字符和字符出现的个数。
        while True:
            try:
                chr = next(p)
                if chr >= 'a' and chr <= 'z' or chr >= 'A' and chr <= 'Z' or chr >= '0' and chr <= '9' or chr == '.':
                    if len(curFigure) == 1:
                        curFigure.append(1)
                    regExpList.append(curFigure)
                    curFigure = []
                    curFigure.append(chr)
                elif chr == '*':
                    curFigure.append('*')
            except StopIteration:
                if len(curFigure) == 1:
                    curFigure.append(1)
                    regExpList.append(curFigure)
                elif len(curFigure) == 2:
                    regExpList.append(curFigure)
                break
        regExpList = iter(regExpList)
        flagNextChr = 1
        flagNextItem = 2 # 0： 不读取下一个; 1：读取下一个，并将当前的赋值给lastRegItem;  2：读取下一个，但是不将当前的赋值给lastRegItem
        lastChr
        lastRegItem = None
        while True:
            try:
                if flagNextChr == 1:
                    chr = next(s)
            except StopIteration:
                # 匹配成功的情况有两种：
                # 1. s到末尾时，regExpList也到达末尾
                # 2. s到达末尾时，regExpList后面还有元素。但是后面元素的出现个数都是*
                try:
                    while True:
                        lastRegItem = regItem
                        regItem = next(regExpList)
                        if regItem[1] == "*" :
                            return True
                        elif lastRegItem[1] == '*' and (regItem[0] == lastRegItem[0] or regItem[0] == '.' or lastRegItem[0] == '.'):
                            return True
                        else:
                            return False
                except:
                    return True
            try:
                if flagNextItem == 1:
                    lastRegItem = regItem
                if flagNextItem >= 1:
                    regItem = next(regExpList)
            except StopIteration:
                return False
            flagNextChr = 0
            flagNextItem = 0
            if chr == regItem[0] or regItem[0] == '.':
                # if regItem[0] == '.': # 如果跟'.'匹配成功，那么就把正则表中的'.'替换为匹配到的字符
                #     regItem[0] = chr
                if regItem[1] == 1:
                    flagNextChr = 1
                    flagNextItem = 1
                    continue
                elif regItem[1] == '*':
                    flagNextChr = 1
            elif regItem[1] == '*':  # 匹配失败，但是正则表达式中字符的出现次数可以为0
                flagNextChr = 0
                flagNextItem = 1
                continue
            elif lastRegItem != None and lastRegItem[1] == '*' and (regItem[0] == lastRegItem[0] or regItem[0] == '.' or lastRegItem[0] == '.'): # 匹配失败，但是正则表达式中的当前字符可以并归到上个字符
                flagNextChr = 0
                flagNextItem = 2 # 如果是 "aaab" 和 "a*..b"匹配。匹配完第一个"."后，再匹配第二个点，则需要把第一个点的出现次数改为"*"，否则第二个点会匹配失败
                regItem[1] = '*'
                continue
            else:
                return False

if __name__ == "__main__":
    s = Solution()
    print (s.isMatch("ab", ".*"))

# 感觉难就难在，要求是非贪婪匹配。
# 如果尝试归并，不太好做：
#   如果表达式是 "a*a"， 那可以在处理表达式时，将其归并为 "a*"
#   但如果表达式是 "a*."，那必须支持回溯。判断'.'如果不匹配，就判断前面的'a'是否匹配
# 所以，用回溯的方法
#   如果当前的符号匹配失败，如果满足如下两个要求，则认为匹配成功
#       1.上一个字符的出现次数为'*'
#       2.当前字符和上一个字符相同，或其中一个为'.'
#   但也有特殊特殊的情况：
#       如果是 "aaab" 和 "a*..b"匹配。匹配完第一个"."后，再匹配第二个点，则需要把第一个点的出现次数改为"*"，否则第二个点会匹配失败
#   这种情况，无法匹配成功，因此改为递归算法。
class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        lists = [] #list中包含numRows个list
        curIndex = 0 #下一个字符属于第curIndex个list
        direction = 1 #下一个字符所属的list是当前list的索引+direction。 direction可取 1 或 -1 或 0（如果numRows为1）
        for i in range(0, numRows):
            lists.append([])
        for j in range(0, len(s)):
            #print curIndex, s[j]
            lists[curIndex].append(s[j])
            if numRows == 1:
                direction = 0
            elif curIndex == 0:
                direction = 1
            elif curIndex == numRows - 1:
                direction = -1
            curIndex += direction
        strAfterZigZag = ""
        for lst in lists:
            strAfterZigZag += "".join(lst)
        return strAfterZigZag
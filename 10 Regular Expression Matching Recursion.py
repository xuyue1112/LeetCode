class Solution:
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        if not p: # 如果p为空，s必为空，才能匹配成功。但如果s为空，p可以不为空，比如p还剩"a*"
            return not s
        first_match = bool(s) and p[0] in {s[0], '.'}

        if bool(p[1:]) and p[1] == "*":
            # 在答案中，把第二种和第三种情况合并了
            return first_match and self.isMatch(s[1:], p) or \
                   self.isMatch(s, p[2:])
        else:
            return first_match and self.isMatch(s[1:], p[1:])


if __name__ == "__main__":
    s = Solution()
    print (s.isMatch("bbbba", ".*a*a"))



# 两种算法
# 1. 蛮力算法，计算任意两个木板的容量 O(n^2)
# 2. 从两边到中间遍历
class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        left, right = 0, len(height)-1
        maxArea = 0
        while left < right:
            maxArea = max(maxArea, (right - left) * min(height[left], height[right]))
            if height[left] <= height[right]:
                left += 1
            else:
                right -= 1
        return maxArea


class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        length = len(nums)
        if length < 3:
            return []
        result = []
        for i in range(0, length-2):
            if i >= 1 and nums[i] == nums[i-1]: #避免重复的情况
                continue
            lo, hi = i+1, length-1
            while lo < hi:
                #print (nums[i], nums[lo], nums[hi])
                if nums[i] + nums[lo] + nums[hi] < 0:
                    lo += 1
                elif nums[i] + nums[lo] + nums[hi] > 0:
                    hi -= 1
                else:
                    result.append([nums[i], nums[lo], nums[hi]])
                    while lo+1 < length and nums[lo] == nums[lo+1]:
                        lo += 1
                    while hi-1 >= 0 and nums[hi] == nums[hi-1]:
                        hi -= 1
                    lo += 1
        return result

if __name__ == "__main__":
    S = Solution()
    print (S.threeSum([-1, 0, 1, 2, -1, -4]))
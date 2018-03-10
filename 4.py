class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        length1 = len(nums1)
        length2 = len(nums2)
        if length1 > length2:
            nums1, nums2, length1, length2 = nums2, nums1, length2, length1
        start = 0
        end = length1
        while(True):
            i = (start + end) / 2
            j = (length1 + length2) / 2 - i
            if (i == 0 or j == length2 or nums1[i-1] <= nums2[j]) and (i == length1 or j == 0 or nums2[j-1] <= nums1[i]):
                if i == length1:
                    min_right = nums2[j]
                elif j == length2:
                    min_right = nums1[i]
                else:
                    min_right = min(nums1[i],nums2[j])
                if (length1 + length2) % 2 == 1:
                    return float(min_right)
                if i == 0:
                    max_left = nums2[j-1]
                elif j == 0:
                    max_left = nums1[i-1]
                else:
                    max_left = max(nums1[i-1], nums2[j-1])
                return (max_left + min_right) / 2.0
            elif i == length1 or (i > 0 and nums1[i-1] >= nums2[j]):
                end = i-1
                continue
            elif j == length2 or (i < length1 and nums2[j-1] >= nums1[i]):
                start = i+1
                continue
            
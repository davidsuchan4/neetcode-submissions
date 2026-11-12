class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        newNums = sorted(nums1 + nums2)
        size = len(newNums)
        
        if size % 2 == 0:
            return ((newNums[size // 2] + newNums[(size - 1) // 2]) / 2)
        else:
            return newNums[size // 2]
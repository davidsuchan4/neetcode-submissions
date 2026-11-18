class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        size = len(nums)
        ret = []
        visited = set()
        for i in range(size):
            cur = 0
            l = i + 1
            r = size - 1
            while l < r:
                cur = nums[i] + nums[l] + nums[r]
                if cur < 0:
                    l += 1
                elif cur > 0:
                    r -= 1
                else:
                    if (nums[i], nums[l], nums[r]) not in visited:
                        ret.append([nums[i], nums[l], nums[r]])
                        visited.add((nums[i], nums[l], nums[r]))
                    r -= 1
                    l += 1
        return ret


            



        
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        for i, num in enumerate(nums):
            if abs(num) >= len(nums):
                print('hi', num)
                continue
            print(num)
            nums[abs(num)] *= -1
        flag = False
        for i, num in enumerate(nums):
            if num < 0:
                continue
            elif num == 0:
                for j, n in enumerate(nums):
                    if abs(n) == i:
                        flag = True
                        break
                if flag:
                    continue
                else:
                    return i
            else:
                return i
        return len(nums)
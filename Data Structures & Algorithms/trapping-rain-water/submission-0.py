class Solution:
    def trap(self, height: List[int]) -> int:
        maxWater = [0]*len(height)
        i, j = 0, len(height) - 1
        curCap = 0
        while(i < j):
            curCap = max(curCap, min(height[i], height[j]))
            maxWater[i], maxWater[j] = curCap - min(curCap, height[i]), curCap - min (curCap, height[j])
            if height[i] < height[j]:
                i += 1
            else:
                j -= 1
        return sum(maxWater)

        
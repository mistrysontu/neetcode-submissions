class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        '''
            3,4,2,3,1,1,0
        '''
        mat = [-1 for i in range(len(cost))]
        mat[-1], mat[-2] = cost[-1], cost[-2]
        if len(cost) <= 2:
            return min(cost)
        for i in range(len(cost)-3, -1, -1):
            mat[i] = min(mat[i+1], mat[i+2]) + cost[i]

        return min(mat[0], mat[1])
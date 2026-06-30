class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n = len(gas)
        gas = gas*2
        cost = cost*2
        '''
        y --> ... [-->  x (0, +ve) -->] .. --> z (-ve)
        '''
        start, i = 0, 0
        gasLeft = 0
        while i < len(gas):
            gasLeft += (gas[i] - cost[i])
            print(start, i, gasLeft)
            if gasLeft < 0:
                start = i+1
                gasLeft = 0
            if i - start == n:
                return start
            i += 1
        return -1
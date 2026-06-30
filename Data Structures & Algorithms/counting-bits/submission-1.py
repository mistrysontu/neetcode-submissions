class Solution:
    def countBits(self, n: int) -> List[int]:
        res = [0 for i in range(n+1)]
        x = 1
        cnt = 1
        i = 1
        while i <= n:
            if x*2 == i:
                x = x << 1
                cnt += 1
            res[i] = 1 + res[i-x]
            print(i, x)
            i += 1

        return res
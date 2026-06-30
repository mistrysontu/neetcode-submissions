class Solution:
    def reverse(self, x: int) -> int:
        n = 0
        sign = (x < 0)
        x = abs(x)
        while x:
            n = (n * 10) + (x % 10)
            print(n)
            if n >= (2**32): return 0
            x = x // 10
        return -n if sign else n
        
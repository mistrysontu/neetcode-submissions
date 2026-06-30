class Solution:
    def reverseBits(self, n: int) -> int:
        x = 0
        i = 0
        while n:
            x = (x << 1) + (n & 1)
            n = n >> 1
            i += 1
        while i < 32:
            x = x << 1
            i += 1
        return x
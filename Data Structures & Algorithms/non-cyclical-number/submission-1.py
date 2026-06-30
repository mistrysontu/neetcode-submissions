class Solution:
    def isHappy(self, n: int) -> bool:
        s = set()
        while n:
 
            x = 0
            while n:
                x += (n % 10)**2
                n = n // 10
            n = x
            print(n)
            if n == 1:
                return True
            if n in s:
                return False
            s.add(n)
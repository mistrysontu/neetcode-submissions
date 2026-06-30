class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        x = dict()
        for i in s:
            if i not in x.keys():
                x[i] = 1
            else:
                x[i] += 1

        for i in t:
            if i not in x.keys():
                return False
            x[i] -= 1

        # print(x.items())
        for i in x.values():
            if i != 0:
                return False

        return True
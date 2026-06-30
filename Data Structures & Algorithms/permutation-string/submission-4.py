class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        j = len(s1)
        charSet = {}
        for i in s1:
            charSet[i] = 1+ charSet.get(i, 0)
        i = 0
        while i <= len(s2) - len(s1):
            flag = False
            k = i
            tempSet = charSet.copy()
            print()
            while k < i+len(s1):
                print(i, k, i+len(s1))
                if s2[k] not in tempSet:
                    flag = True
                    break
                tempSet[s2[k]] -= 1
                k += 1
                if min(tempSet.values()) < 0:
                    # flag = True
                    break
            print(tempSet)
            if flag:
                i = k
            elif not max(tempSet.values()):
                return True
            i += 1
        return False
        
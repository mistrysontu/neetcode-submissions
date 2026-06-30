class Solution:
    def minWindow(self, s: str, t: str) -> str:
        '''
        aab
        pqaxxa|ab|xaab
        a = -1
        b = 0
        '''
        res = 1001
        ret = ""
        charSet = {}
        for c in t:
            charSet[c] = 1 + charSet.get(c, 0)

        i, j = 0, len(t)
        while i <= len(s) - len(t):
            tempSet = charSet.copy()
            k = i
            while k < len(s):
                print(ret)
                if s[k] in tempSet.keys():
                    tempSet[s[k]] -= 1
                if max(tempSet.values()) <= 0:
                    if k-i+1 < res:
                        res = k-i+1
                        print('hi ', i, k-i+1)
                        ret = s[i: k+1]
                    # res = min(res, k-i+1)
                while max(tempSet.values()) <= 0:                    
                    if s[i] in tempSet.keys():
                        tempSet[s[i]] += 1
                    if max(tempSet.values()) > 0:
                        break
                    print(tempSet, s[i])
                    i += 1
                    if k-i+1 < res:
                        print('bye ', i, k-i+1)
                        res = k-i+1
                        ret = s[i: k+1]
                    
                print('boo ', i, k, res)
                k += 1
            i += 1
        return ret                
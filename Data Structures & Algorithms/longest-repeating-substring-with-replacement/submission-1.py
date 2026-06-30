class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        '''
            abcb bb, k = 2
        '''
        i, j = 0, 0
        if not len(s): return 0
        res = 0
        hashMap = {s[i]: 1}

        while True:
            if i > j or j >= len(s):
                break
            
            while True:
                j += 1
                if j >= len(s): break
                hashMap[s[j]] = 1 + hashMap.get(s[j], 0)
                mx_cnt = max(hashMap.values())
                windowLen = j - i + 1
                if windowLen - mx_cnt > k:
                    hashMap[s[i]] = hashMap.get(s[i]) - 1
                    i += 1
                    break
                res = max(res, windowLen)
        return res
            

        
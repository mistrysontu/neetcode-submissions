class Solution:

    def encode(self, strs: List[str]) -> str:
        s = ""
        for st in strs:
            s += str(len(st)) + ":" + st
        return s

    def decode(self, s: str) -> List[str]:
        res = []
        i = 0
        while i < len(s):
            j = i
            while s[j] != ':':
                j += 1
            length = int(s[i:j])
            x = s[j+1:j+length+1]
            res.append(x)
            i = j + length + 1
            # print(i, length)

        return res

            

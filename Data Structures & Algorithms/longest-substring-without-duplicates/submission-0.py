class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l = 0
        charSet = set()
        longestNow = ""
        longestOverAll = ""

        for i in range(len(s)):
            while s[i] in charSet:
                charSet.remove(s[l])
                l = l + 1
            charSet.add(s[i])
            longestNow = s[l:i+1]
            if len(longestNow) > len(longestOverAll):
                longestOverAll = longestNow
        print(longestOverAll)
        return len(longestOverAll)
        
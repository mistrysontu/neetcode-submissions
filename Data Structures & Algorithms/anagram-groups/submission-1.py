class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashmap = dict()
        for s in strs:
            elem = "".join(sorted(s))
            print(elem)
            if elem in hashmap:
                hashmap[elem].append(s)
            else:
                hashmap[elem] = [s]
        return list(hashmap.values())
        
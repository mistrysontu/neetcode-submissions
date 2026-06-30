class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        '''
            1 2 3 4 5
            -inf 7 8 9 inf
            half - i + 2
            4 - 1 -1 -1
            8 + 4 
            6 - 2 -2


            1 2
            3 4 5 6 7 8
        '''
        # we will run binary search on nums1, so chose the smaller array as nums1
        if len(nums2) < len(nums1):
            nums2, nums1 = nums1, nums2
        # actural median should be here
        nums1 = [float('-inf')] + (nums1 + [float('inf')])
        nums2 = [float('-inf')] + (nums2 + [float('inf')])

        half = (len(nums1) + len(nums2)) // 2

        l, r = 0, len(nums1) - 1

        while True:
            i = (l + r) // 2
            j = half - (i+2)

            L1, R1 = nums1[i], nums1[i+1]
            L2, R2 = nums2[j], nums2[j+1]
            print(L1, L2)
            print(R1, R2)
            print()
            if (L1 <= R2 and L2 <= R1):
                if (len(nums1) + len(nums2)) % 2:
                    return min(R1, R2)
                return (max(L1, L2) + min(R1, R2))/2
            
            elif L1 > R2:
                r = i - 1
            else:
                l = i + 1

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums2) < len(nums1):
            nums1, nums2 = nums2, nums1

        nums1 = [float('-inf')] + nums1 + [float('inf')]
        nums2 = [float('-inf')] + nums2 + [float('inf')]
        total_len = len(nums1) + len(nums2)
        half_len = total_len // 2

        i, j = 0, len(nums1) - 1

        while True:
            mid = (i+j) // 2
            mid1 = half_len - mid - 2

            L1, R1 = nums1[mid], nums1[mid+1]
            L2, R2 = nums2[mid1], nums2[mid1+1]

            if (L1 <= R2 and L2 <= R1):
                if total_len % 2:
                    return min(R1, R2)
                else:
                    return (min(R1, R2) + max(L1, L2)) / 2
            elif L1 > R2:
                j = mid - 1
            else:
                i = mid + 1
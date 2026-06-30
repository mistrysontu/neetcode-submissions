class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        minHeap = [(i**2 + j**2, i, j) for (i, j) in points]
        heapq.heapify(minHeap)
        res = []
        for _ in range(k):
            _, i, j = heapq.heappop(minHeap)
            res.append([i, j])
        return res
import heapq

# Quick select O(n)
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        self.quick_select(points, 0, len(points) - 1, k)
        return points[:k]
    
    def quick_select(self, points, start, end, k):
        if start >= end:
            return
        
        l, r = start, end
        pivot = self.get_distance(points[(start + end) >> 1])
        
        while l <= r:  # triky
            while l <= r and self.get_distance(points[l]) < pivot:
                l += 1
            while l <= r and self.get_distance(points[r]) > pivot:
                r -= 1
            if l <= r:
                points[l], points[r] = points[r], points[l]
                l += 1
                r -= 1
        
        if r >= k:  # tricky
            self.quick_select(points, start, r, k)
        if l <= k:
            self.quick_select(points, l, end, k)
            
    
    def get_distance(self, point):
        return point[0] ** 2 + point[1] ** 2


# Maxheap O(nlogk)
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = []
        
        for point in points:
            distance = self.get_distance(point)
            heapq.heappush(heap, (-distance, -point[0], -point[1]))
            
            if len(heap) > k:
                heapq.heappop(heap)
        
        ret = []
        while heap:
            _, x, y = heapq.heappop(heap)
            ret.append([-x, -y])
        
        ret.reverse()
        return ret
            
    
    def get_distance(self, point):
        return point[0] ** 2 + point[1] ** 2


# Sort O(nlogn)
# class Solution:
#     def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
#         if len(points) < k:
#             return []
        
#         points.sort(key = lambda x:(x[0] ** 2 + x[1] ** 2))
#         return points[:k]
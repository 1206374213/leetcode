# Definition for a point.
# class Point(object):
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b
# Definition for a point.
# class Point(object):
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b
# from fractions import Fraction
# class Solution(object):
#     def maxPoints(self, points):
#         ans=0
#         length=len(points)
#         if length<3:
#             return length
#         for i in xrange(length):
#             dict={'inf':0}
#             same=1
#             for j in xrange(i,length):
#                 if i==j:
#                     continue
#                 if points[i].x==points[j].x and points[i].y!=points[j].y:
#                     dict['inf']+=1
#                 elif points[i].x!=points[j].x:
#                     slope=Fraction(points[i].y-points[j].y,points[i].x-points[j].x)
#                     if slope in dict:
#                         dict[slope]+=1
#                     else:
#                         dict[slope]=1
#                 else:
#                     same+=1
#             ans=max(ans,max(dict.values())+same)
#         return ans
            
        """
        :type points: List[Point]
        :rtype: int
        """
import fractions
from collections import defaultdict

class Solution(object):
    def maxPoints(self, points):
        ans = 0
        for i in range(len(points)):
            p1 = points[i]
            t = defaultdict(int)
            same = 0
            for j in range(i, len(points)):
                p2 = points[j]
                dx, dy = p1.x - p2.x, p1.y - p2.y
                gcd = fractions.gcd(dx, dy)
                if gcd == 0:
                    same += 1
                else:
                    t[(dx / gcd, dy / gcd)] += 1
            ans = max(ans, max(t.values() or [0]) + same)
        return ans
            
        """
        :type points: List[Point]
        :rtype: int
        """
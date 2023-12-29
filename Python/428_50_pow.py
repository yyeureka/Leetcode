# Recursion
class Solution:
    """
    @param x {float}: the base number
    @param n {int}: the power number
    @return {float}: the result
    """
    def myPow(self, x, n):
        # write your code here
        if 0 == n:
            return 1
        
        res = self.myPow(x, int(n / 2))

        if n & 1:
            if n < 0:
                return res * res / x
            else:
                return res * res * x
        return res * res


# # loop
# class Solution:
#     """
#     @param x {float}: the base number
#     @param n {int}: the power number
#     @return {float}: the result
#     """
#     def myPow(self, x, n):
#         # write your code here
#         if 0 == x:
#             return 0
#         elif 1 == x:
#             return x

#         flag = False
#         if n < 0:
#             n = -n
#             flag = True
        
#         res = 1
#         while n > 0:
#             if 1 == n & 1:
#                 res *= x
            
#             x *= x
#             n >>= 1

#         if flag:
#             return 1 / res
#         return res
        
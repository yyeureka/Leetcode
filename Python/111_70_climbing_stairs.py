class Solution:
    """
    @param n: An integer
    @return: An integer
    """
    def climb_stairs(self, n: int) -> int:
        # write your code here
        if n <= 1:
            return n

        pre_pre = 1
        pre = 1

        for i in range(2, n + 1):
            pre_pre, pre = pre, pre + pre_pre
        
        return pre

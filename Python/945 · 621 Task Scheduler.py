# 所消耗的时间主要受制于出现次数最多的那个字母

class Solution:
    """
    @param tasks: the given char array representing tasks CPU need to do
    @param n: the non-negative cooling interval
    @return: the least number of intervals the CPU will take to finish all the given tasks
    """

    def least_interval(self, tasks: str, n: int) -> int:
        # write your code here
        dict = {}
        for i in tasks:
            dict[i] = dict.get(i, 0) + 1

        counts = list(dict.values())
        max_count = max(dict.values())
        res = (max_count - 1) * (n + 1) + counts.count(max_count)  # 最后几个可省略 cooling

        return max(len(tasks), res)  # 可能有零散的几个

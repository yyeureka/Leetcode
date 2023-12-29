from typing import (
    List,
)


class Solution:
    """
    @param time_points: a list of 24-hour clock time points
    @return: the minimum minutes difference between any two time points in the list
    """

    def find_min_difference(self, time_points: List[str]) -> int:
        # Write your code here
        if not time_points:
            return 0

        time_points.sort(key=lambda x: (x[:2], x[3:]))
        res = 720

        for i in range(len(time_points)):
            cur = int(time_points[i][:2]) * 60 + int(time_points[i][3:])

            if 0 == i:
                pre = int(time_points[-1][:2]) * 60 + int(time_points[-1][3:])
                res = min(res, cur + 1440 - pre, pre - cur)
            else:
                res = min(res, cur - pre, pre + 1440 - cur)

            pre = cur

        return res


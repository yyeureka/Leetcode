Description = '''
您将获得一个使用这三个可能值初始化的 m×n 2D 网格。
-1 - 墙壁或障碍物。
0 - 门。
INF - Infinity是一个空房间。我们使用值 2 ^ 31 - 1 = 2147483647 来表示INF，您可以假设到门的距离小于 2147483647。
在代表每个空房间的网格中填入到距离最近门的距离。如果不可能到达门口，则应填入 INF
输入：
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
返回：
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
  
解题思路：
1、从每个0出发，递归搜索更新所有INF
2、碰到-1或0停止当前路径
3、碰到空房间已有的距离<=当前距离，停止当前路径
'''

INF = 2147483647


def search_left(rooms, i_idx, j_idx, distance):
    if j_idx > 0:
        j_idx -= 1
        distance += 1
        next_grid = rooms[i_idx][j_idx]
        if next_grid == -1 or next_grid == 0:
            return
        else:
            if distance < next_grid:  #没更新上的地方的其他节点就不用考虑了 只会更大
                rooms[i_idx][j_idx] = distance
                search_left(rooms, i_idx, j_idx, distance)
                search_up(rooms, i_idx, j_idx, distance)
                search_down(rooms, i_idx, j_idx, distance)
    else:
        return


def search_right(rooms, i_idx, j_idx, distance):
    n = len(rooms[0])
    if j_idx < (n - 1):
        j_idx += 1
        distance += 1
        next_grid = rooms[i_idx][j_idx]
        if next_grid == -1 or next_grid == 0:
            return
        else:
            if distance < next_grid:
                rooms[i_idx][j_idx] = distance
                search_right(rooms, i_idx, j_idx, distance)
                search_up(rooms, i_idx, j_idx, distance)
                search_down(rooms, i_idx, j_idx, distance)
    else:
        return


def search_up(rooms, i_idx, j_idx, distance):
    if i_idx > 0:
        i_idx -= 1
        distance += 1
        next_grid = rooms[i_idx][j_idx]
        if next_grid == -1 or next_grid == 0:
            return
        else:
            if distance < next_grid:
                rooms[i_idx][j_idx] = distance
                search_left(rooms, i_idx, j_idx, distance)
                search_right(rooms, i_idx, j_idx, distance)
                search_up(rooms, i_idx, j_idx, distance)
    else:
        return


def search_down(rooms, i_idx, j_idx, distance):
    m = len(rooms)
    if i_idx < (m - 1):
        i_idx += 1
        distance += 1
        next_grid = rooms[i_idx][j_idx]
        if next_grid == -1 or next_grid == 0:
            return
        else:
            if distance < next_grid:
                rooms[i_idx][j_idx] = distance
                search_left(rooms, i_idx, j_idx, distance)
                search_right(rooms, i_idx, j_idx, distance)
                search_down(rooms, i_idx, j_idx, distance)
    else:
        return


class Solution:
    """
    @param rooms: m x n 2D grid
    @return: nothing
    """
    def wallsAndGates(self, rooms):
        if rooms:
            m = len(rooms)
            n = len(rooms[0])
            for i in range(0, m):
                for j in range (0, n):
                    if rooms[i][j] == 0:
                        search_left(rooms, i, j, 0)
                        search_right(rooms, i, j, 0)
                        search_up(rooms, i, j, 0)
                        search_down(rooms, i, j, 0)

        return rooms


# rooms = []
# rooms = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
rooms = [[0,2147483647,2147483647,0,2147483647,0,-1,2147483647,-1,0,0,-1,-1,2147483647,-1,2147483647,2147483647,0,2147483647,2147483647,0,0,-1,2147483647,-1,2147483647,-1,2147483647,2147483647,0,0,0],[0,2147483647,0,2147483647,0,0,-1,-1,-1,2147483647,2147483647,2147483647,2147483647,2147483647,-1,2147483647,0,0,2147483647,2147483647,2147483647,0,0,0,0,-1,2147483647,-1,2147483647,0,2147483647,0],[0,0,0,0,0,-1,2147483647,-1,-1,2147483647,2147483647,2147483647,2147483647,2147483647,0,0,0,-1,0,-1,0,2147483647,-1,-1,0,2147483647,-1,0,-1,2147483647,-1,-1],[0,2147483647,2147483647,0,-1,-1,-1,0,0,-1,0,0,0,0,0,2147483647,2147483647,2147483647,2147483647,0,-1,0,-1,0,-1,0,2147483647,-1,-1,-1,-1,-1],[2147483647,0,0,0,2147483647,2147483647,2147483647,0,-1,0,-1,-1,-1,-1,0,0,2147483647,2147483647,2147483647,-1,-1,-1,-1,2147483647,-1,-1,0,0,0,2147483647,-1,0],[0,-1,-1,-1,-1,-1,2147483647,-1,0,2147483647,-1,2147483647,-1,-1,0,0,-1,0,-1,-1,-1,-1,2147483647,0,2147483647,-1,-1,-1,0,2147483647,0,2147483647],[2147483647,0,-1,-1,-1,-1,-1,0,0,0,2147483647,0,0,2147483647,0,-1,-1,2147483647,-1,-1,0,2147483647,0,0,2147483647,-1,2147483647,2147483647,0,0,-1,2147483647],[2147483647,-1,2147483647,-1,-1,2147483647,2147483647,0,-1,2147483647,-1,2147483647,0,2147483647,0,0,2147483647,2147483647,2147483647,0,0,-1,-1,-1,0,-1,-1,0,-1,-1,-1,-1],[2147483647,2147483647,-1,0,-1,-1,2147483647,2147483647,0,2147483647,0,2147483647,-1,0,-1,0,-1,2147483647,0,2147483647,-1,2147483647,-1,2147483647,2147483647,-1,2147483647,0,0,-1,-1,0],[-1,0,2147483647,2147483647,0,0,-1,0,0,-1,0,-1,-1,-1,-1,-1,2147483647,0,-1,2147483647,-1,0,-1,0,2147483647,2147483647,2147483647,0,-1,0,-1,-1],[2147483647,-1,-1,2147483647,0,-1,-1,0,-1,-1,0,0,2147483647,-1,-1,0,-1,-1,2147483647,0,0,2147483647,0,2147483647,-1,0,0,-1,0,-1,-1,2147483647]]
s = Solution()
result = s.wallsAndGates(rooms)
print(result)

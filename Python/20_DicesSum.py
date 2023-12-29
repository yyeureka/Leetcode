Description = '''
扔 n 个骰子，向上面的数字之和为 S。给定 Given n，请列出所有可能的 S 值及其相应的概率
如：给定 n = 1，返回 [ [1, 0.17], [2, 0.17], [3, 0.17], [4, 0.17], [5, 0.17], [6, 0.17]]
解题思路：
1、n个色子和为n~6n
2、和的总数为6^n次方
3、和的分布是对称的，顶点为7n/2，n为奇数时有两个
4、sum（n，s）= sum（n-1，s-1）+ sum（n-1，s-2）+ sum（n-1，s-3）+ sum（n-1，s-4）+ sum（n-1，s-5）+ sum（n-1，s-6）
   如s-i<n-1，或s-i>6(n-1)， sum（n-1，s-i）结果为0
   初始sum（1，1）...sum（1，6）为1
5、递归方法做了很多重复工作，会超时！！枚举法列出1~n个色子和的分布的表格
'''

#递归方法
# def get_sum_cnt(sum, dice_num):
#
#     if sum < dice_num or sum > 6 * dice_num:
#         return 0
#
#     if dice_num == 1:
#         return 1
#
#     count = get_sum_cnt(sum - 1, dice_num - 1) + get_sum_cnt(sum - 2, dice_num - 1)\
#             + get_sum_cnt(sum - 3, dice_num - 1) + get_sum_cnt(sum - 4, dice_num - 1)\
#             + get_sum_cnt(sum - 5, dice_num - 1) + get_sum_cnt(sum - 6, dice_num - 1)\
#
#     return count


#枚举出所有色子和
def get_sum_cnt(dice_num):
    dsc = [[0 for col in range(6 * dice_num + 1)]for row in range(dice_num + 1)]
    dsc[1][1] = 1
    dsc[1][2] = 1
    dsc[1][3] = 1
    dsc[1][4] = 1
    dsc[1][5] = 1
    dsc[1][6] = 1

    for i in range(2, dice_num + 1):
        for j in range(i, 6 * i + 1):
            cnt = 0
            if j <= (7 * i / 2):
                if j - 1 > 0:
                    cnt += dsc[i - 1][j - 1]
                if j - 2 > 0:
                    cnt += dsc[i - 1][j - 2]
                if j - 3 > 0:
                    cnt += dsc[i - 1][j - 3]
                if j - 4 > 0:
                    cnt += dsc[i - 1][j - 4]
                if j - 5 > 0:
                    cnt += dsc[i - 1][j - 5]
                if j - 6 > 0:
                    cnt += dsc[i - 1][j - 6]
                dsc[i][j] = cnt
            else:
                dsc[i][j] = dsc[i][7 * i - j]

    return dsc


class Solution:
    # @param {int} n an integer
    # @return {tuple[]} a list of tuple(sum, probability)
    def dicesSum(self, n):
        dice_sum_map = get_sum_cnt(n)
        result = []
        sum_total = pow(6, n)

        for i in range(n * 1, n * 6 + 1):
            sum_prob = (i, dice_sum_map[n][i] / sum_total)
            result.append(sum_prob)

        return result


n = 2
s = Solution()
print(s.dicesSum(n))


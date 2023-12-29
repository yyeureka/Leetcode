Description = '''
给定一个n个邮件地址字符串的数组.
求出电子邮件组的数量，每个组应具有多个电子邮件地址（地址可以重复）。如果两个字符串在转换后具有相同的值，则它们位于同一组中。
邮件地址处理时遵循以下规则:
1、在字符`'@'之前忽略所有的字符 '.'.
2、在字符`'@'之前忽略字符 '+'以及它后面的所有子字符串.
3、电子邮件组至少有两个相同的电子邮件地址
'''


def delete_format(email):
        s1 = list(email)
        result = ''
        flag1 = False  #为True时开始忽略@前的+和后面的字符
        flag2 = False  #@后置为True，不忽略任意字符
        for i in s1:
            if i == '@':
                flag2 = True

            if not flag2:
                if '.' == i:
                    continue
                elif '+' == i:
                    flag1 = True
                    continue

                if flag1:
                    continue

            result += i
        return result


class Solution:
    """
    @param emails: Original email
    @return: Return the count of groups which has more than one email address in it.
    """
    def countGroups(self, email_list):
        group = {}
        number = 0
        for i in range(0, len(email_list)):
            pattern = delete_format(email_list[i])
            if pattern in group:
                if 0 == group[pattern]:
                    number += 1
                    group[pattern] = 1
            else:
                group[pattern] = 0

        return number


s = Solution()
emails = ["abc.bc+c+d@jiuzhang.com", "abcbc+d@jiuzhang.com", "abc.bc+cd@jiuzhang.com"]
print(s.countGroups(emails))

"""
Definition of ListNode
class ListNode(object):
    def __init__(self, val, next=None):
        self.val = val
        self.next = next
"""

# 1、A+B和B+A肯定是相等的长度
#    A走完时接B
#    B走完时接A
#    A和B相等时即为intersection或A、B的末尾NULL
# 2、先分别得到A和B两个linkedlist的长度
#    底部对齐了找相等的node


class Solution:
    """
    @param headA: the first list
    @param headB: the second list
    @return: a ListNode
    """
    def getIntersectionNode(self, headA, headB):
        # write your code here
        node1 = headA
        node2 = headB

        while node1 != node2:
            node1 = node1.next if node1 else headB
            node2 = node2.next if node2 else headA

        return node1
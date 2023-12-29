"""
Definition of ListNode
class ListNode(object):
    def __init__(self, val, next=None):
        self.val = val
        self.next = next
"""

# 1、先找确定存在cycle
# 2、when meet，slow走了k步，fast走了2k步，2k-k=nr，k=nr
#    从start到cycle begin的距离为s，cycle begin到meet point为m=k-s，s=nr-m=(n-1)r+(r-m)
#    slow从start出发，fast从meet point出发，meet的时候即为cycle begin

class Solution:
    """
    @param head: The first node of linked list.
    @return: The node where the cycle begins. if there is no cycle, return null
    """

    def detectCycle(self, head):
        # write your code here
        fast = head
        slow = head

        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next

            if slow == fast:
                slow = head

                while slow != fast:
                    fast = fast.next
                    slow = slow.next

                return slow

        return None
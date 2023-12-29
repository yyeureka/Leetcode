import heapq

# Minheap O(nlogk)
# Divide&conquer O(nlogk)
# Bottom up 2 merge O(nlogk)


# Minheap nlog(k)
ListNode.__lt__ = lambda x, y: (x.val < y.val)

class Solution:
    """
    @param lists: a list of ListNode
    @return: The head of one sorted list.
    """

    def mergeKLists(self, lists):
        # write your code here
        minheap = []
        dummy = ListNode(0)
        node = dummy

        for head in lists:
            if head:  # tricky
                heapq.heappush(minheap, head)

        while minheap:
            head = heapq.heappop(minheap)
            node.next = head
            node = head

            if head.next:
                heapq.heappush(minheap, head.next)

        return dummy.next


# Divide&conquer O(nlogk)
class Solution:
    """
    @param lists: a list of ListNode
    @return: The head of one sorted list.
    """

    def mergeKLists(self, lists):
        # write your code here
        ret = self.mergeSort(lists, 0, len(lists) - 1)
        return ret

    def mergeSort(self, lists, start, end):
        if start >= end:
            return lists[start]

        mid = (start + end) >> 1
        left = self.mergeSort(lists, start, mid)
        right = self.mergeSort(lists, mid + 1, end)

        return self.merge2Lists(left, right)

    def merge2Lists(self, list1, list2):
        if not list1:
            return list2
        if not list2:
            return list1

        if list1.val < list2.val:
            list1.next = self.merge2Lists(list1.next, list2)
            return list1
        else:
            list2.next = self.merge2Lists(list1, list2.next)
            return list2


# Botton up 2merge O(nlogk)
class Solution:
    """
    @param lists: a list of ListNode
    @return: The head of one sorted list.
    """

    def mergeKLists(self, lists):
        # write your code here
        size = len(lists)
        while size > 1:
            for i in range(0, size, 2):
                if i + 1 >= size:
                    lists[i >> 1] = lists[i]
                else:
                    lists[i >> 1] = self.merge2Lists(lists[i], lists[i + 1])

            size = (size + 1) >> 1  # tricky

        return lists[0]

    def merge2Lists(self, list1, list2):
        if not list1:
            return list2
        if not list2:
            return list1

        if list1.val < list2.val:
            list1.next = self.merge2Lists(list1.next, list2)
            return list1
        else:
            list2.next = self.merge2Lists(list1, list2.next)
            return list2
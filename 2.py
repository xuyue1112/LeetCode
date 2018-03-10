# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        addOne = 0
        head = ListNode(0)
        cur = head
        while l1 != None or l2 != None or addOne != 0:
            tmpSum = addOne
            if l1 != None:
                tmpSum += l1.val
                l1 = l1.next
            if l2 != None:
                tmpSum += l2.val
                l2 = l2.next
            addOne, tmpSum = divmod(tmpSum, 10)
            tmpNode = ListNode(tmpSum)
            cur.next = tmpNode
            cur = cur.next
        return head.next
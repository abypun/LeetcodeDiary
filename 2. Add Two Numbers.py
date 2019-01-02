# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1.val == 0 and l1.next == None and l2.val == 0 and l2.next == None:
            return ListNode(0)

        lsum = ListNode(0)
        i = l1
        j = l2
        k = lsum
        while i and j:
            k.val = (i.val + j.val) % 10
            carry = (i.val + j.val) / 10
            k.next = ListNode(carry)
            i = i.next
            j = j.next
            k = k.next
        if i != None:
            pass
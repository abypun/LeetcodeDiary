# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution1:
    '''
    :author: Rufeer
    :solution: O(n)
    :runtime: 188 ms
    '''
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        node = ListNode((l1.val+l2.val) % 10)
        carry = (l1.val+l2.val) // 10
        if carry == 1:
            if l1.next == None and l2.next == None:
                node.next = ListNode(1)
            elif l1.next != None and l2.next != None:
                l1.next.val = l1.next.val + 1
                node.next = self.addTwoNumbers(l1.next, l2.next)
            elif l1.next != None:
                node.next = self.addTwoNumbers(ListNode(1), l1.next)
            elif l2.next != None:
                node.next = self.addTwoNumbers(ListNode(1), l2.next)   
        else:
            if l1.next != None and l2.next != None:
                node.next = self.addTwoNumbers(l1.next, l2.next)
            elif l1.next != None:
                node.next = l1.next
            elif l2.next != None:
                node.next = l2.next
        return node

# Test
# s = Solution()
# a = ListNode(1)
# b = ListNode(9)
# b.next = ListNode(9)
# a = ListNode(0)
# b = ListNode(0)
# a = ListNode(9)
# b = ListNode(1)
# b.next = ListNode(9)
# b.next.next = ListNode(8)
# b.next.next.next = ListNode(9)
# a = ListNode(1)
# a.next = ListNode(8)
# b = ListNode(0)
# t = s.addTwoNumbers(a, b)
# while t:
#     print(t.val)
#     t = t.next
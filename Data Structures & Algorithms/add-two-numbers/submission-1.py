# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        p1 = l1
        p2 = l2
        dummy = ListNode()
        new = dummy
        carry = 0

        while p1 or p2 or carry:
            if p1:
                v1 = p1.val
            else:
                v1 = 0
            
            if p2:
                v2 = p2.val
            else:
                v2 = 0
            
            carry, digit = divmod(v1 + v2 + carry, 10)

            new.next = ListNode(digit)
            new = new.next
            p1 = p1.next if p1 else None
            p2 = p2.next if p2 else None
        return dummy.next
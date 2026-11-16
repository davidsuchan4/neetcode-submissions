# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        p1 = head
        p2 = head
        arr = []

        for i in range(right):
            arr.append(p2.val)
            p2 = p2.next
        arr.reverse()
        print(arr)
        for i in range(left - 1):
            p1 = p1.next

        for i in range(right - left + 1):
            p1.val = arr[i]
            p1 = p1.next
        
        return head

        

        
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == nullptr) return nullptr;
        
        ListNode* fast = head;
        ListNode* slow = head;
        int i = 0;

        while(fast != nullptr && fast->next != nullptr){
            if(i >= n){
                slow = slow->next;
            }
            fast = fast->next;
            ++i;
        }
        if(n > i){
            head = head->next;
            return head;
        }
        ListNode* tmp = slow->next->next;
        slow->next->next = nullptr;
        slow->next = tmp;        
        return head;
        
    }
};

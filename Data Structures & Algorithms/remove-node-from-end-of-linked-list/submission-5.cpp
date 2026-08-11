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
        ListNode* p1 = head;
        ListNode* p2 = head;
        
        int counter{};
        while (p1->next != nullptr) {
            if(counter >= n){
                p2 = p2->next;
            }
            ++counter;
            p1 = p1->next;
        }
        if(counter == 0){
            return nullptr;
        }
        if(n > counter){
            return head->next;
        }
        ListNode* temp = p2->next;
        p2->next = p2->next->next;
        temp->next = nullptr;
        return head;

    }
};

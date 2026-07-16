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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* second = reverseList(slow->next);
        slow->next = nullptr;
        ListNode* first = head;

        while(second != nullptr){
            ListNode* tmp1 = first;
            ListNode* tmp2 = second;
            first = first->next;
            second = second->next;
            tmp1->next = tmp2;
            tmp2->next = first;
        }




    }
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* next = head->next;
        ListNode* newHead = head;
        while (next != nullptr) {
            ListNode* temp = next;
            next = next->next;
            temp->next = newHead;
            newHead = temp;
        }
        head->next = nullptr;
        return newHead;
    } 
};

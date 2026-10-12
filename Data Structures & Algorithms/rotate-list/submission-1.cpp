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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head){
            return head;
        }
        ListNode* p1 = head;
        int size{1};
        int counter{};
        while(p1->next){
            p1 = p1->next;
            ++size;
        }
        k %= size;
        if(k == 0){
            return head;
        }
        ListNode* newTail = head;
        for (int i = 0; i < size - k - 1; ++i) {
            newTail = newTail->next;
        }
        p1->next = head;
        head = newTail->next;
        newTail->next = nullptr;
        return head;


    }
};
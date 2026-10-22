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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> indices;
        ListNode* before = head;
        ListNode* curr = before->next;
        ListNode* after = curr->next;
        int idx = 1;
        while (after) {
            if((curr->val > before->val && curr->val > after->val) 
            || curr->val < before->val && curr->val < after-> val){
                indices.push_back(idx);
            }
            ++idx;
            before = curr;
            curr = after;
            after = after->next;
        }
        if(indices.size() < 2){
            return {-1, -1};
        }
        int smallest = INT_MAX;
        for(int i{}; i < indices.size() - 1; ++i){
            smallest = min(smallest, indices[i + 1] - indices[i]);
        }
        return {smallest, indices.back() - indices[0]};

    }
};

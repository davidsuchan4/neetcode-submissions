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
    int pairSum(ListNode* head) {
        vector<int> linkedList;
        ListNode* p1 = head;
        while(p1){
            linkedList.push_back(p1->val);
            p1 = p1->next;
        }
        int size = linkedList.size();
        int maxSum = 0;
        for(int i = size - 1; i >= linkedList.size() / 2; --i){
            maxSum = max(maxSum, linkedList[i] + linkedList[size - 1 - i]);
        }
        return maxSum;

        
    }
};
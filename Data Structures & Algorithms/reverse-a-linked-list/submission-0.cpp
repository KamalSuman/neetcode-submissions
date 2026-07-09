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
    ListNode* reverseList(ListNode* head) {
        ListNode* p = nullptr;
        while(head != NULL){
            ListNode* temp = new ListNode(head->val);
            temp->next = p;
            p = temp;
            head = head->next; 
        }
        return p;
    }
};

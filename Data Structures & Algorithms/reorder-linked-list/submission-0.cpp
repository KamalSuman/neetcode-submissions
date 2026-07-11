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
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(slow != NULL && fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        ListNode* rev = nullptr;
        while(fast!=NULL){
            ListNode* temp = fast->next;
            fast->next = rev;
            rev = fast;
            fast = temp;
        }
        while(rev != NULL){
            ListNode* temp1 = head->next;
            ListNode* temp2 = rev->next;
            head->next = rev;
            rev->next = temp1;
            rev = temp2;
            head = temp1;
        }
    }
};

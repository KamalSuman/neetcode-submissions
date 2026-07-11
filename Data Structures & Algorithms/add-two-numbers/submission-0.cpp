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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode* ans1 = ans;
        int rem = 0;
        while(l1!=NULL && l2!= NULL){
            int l = (l1->val + l2->val + rem)%10;
            rem = (l1->val + l2->val + rem)/10;
            ListNode* temp = new ListNode(l);
            ans->next = temp;
            ans = ans->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL){
            int l = (l1->val + rem)%10;
            rem = (l1->val  + rem)/10;
            ListNode* temp = new ListNode(l);
            ans->next = temp;
            ans = ans->next;
            l1 = l1->next;
        }
        while(l2!=NULL) {
            int l = (l2->val + rem)%10;
            rem = (l2->val + rem)/10;
            ListNode* temp = new ListNode(l);
            ans->next = temp;
            ans = ans->next;
            l2 = l2->next;
        }
        if(rem) ans->next = new ListNode(rem);
        ans1 = ans1->next;
        return ans1;
    }
};

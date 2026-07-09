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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(0);
        ListNode* head = ans;
        while(list1 != NULL &&  list2 != NULL){
            if(list1->val > list2->val){
                ListNode* temp = new ListNode(list2->val);
                ans->next = temp;
                ans = ans->next;
                list2 = list2->next;
            } else {
                ListNode* temp = new ListNode(list1->val);
                ans->next = temp;
                ans = ans->next;
                list1 = list1->next;
            }
        }    
        if(list1 != NULL){
            ans->next = list1;  
        } 
        if(list2 != NULL){
            ans -> next = list2;
        }
        // ans = ans->next;
        return head->next;
    }
};

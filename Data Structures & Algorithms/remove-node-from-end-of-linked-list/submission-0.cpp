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
        ListNode* tmp = nullptr;
        while(head!=NULL){
            ListNode* temp = head->next;
            head->next = tmp;
            tmp = head;
            head = temp;
        }
        ListNode* prev = tmp;
        ListNode* temp1 = tmp;
        head = tmp;
        int n1 = n;
        while(n>1){
            prev = head;
            head = head->next;
            n--;
        }
        prev->next = head->next;
        
        if(n1 == 1){
            ListNode* k1 = temp1->next;
            temp1 = nullptr;
            temp1 = k1;
        }
        head = temp1;
        tmp = nullptr;
        
        // while(head!=NULL){
        //     cout << head->val;
        //     head = head->next;
        // }
        
        while(head!=NULL){
            ListNode* temp = head->next;
            head->next = tmp;
            tmp = head;
            head = temp;
        }
        return tmp;
    }
};

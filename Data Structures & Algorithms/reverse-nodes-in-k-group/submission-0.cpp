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
    void reverse(ListNode* &l1){
        ListNode* rev = NULL;
        while(l1!=NULL){
            ListNode* temp = l1->next;
            l1->next = rev;
            rev = l1;
            l1 = temp;
        }
        l1 = rev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> v;
        int k1 = 0;
        int sz = 0;
        while(head!=NULL){
            if(k1 == 0){
                // cout<<head->val<<endl;
                v.push_back(head);
            }
            if(k1 == k-1){
                ListNode* temp = head;
                temp = head;
                head = head->next;
                sz++;
                temp->next = NULL;
                k1 = 0;
                continue;
            }
            k1++;
            head = head->next;
            sz++;
        } 
        for(int i = 0; i<v.size(); i++){
            if(i == v.size()-1 && (sz - k*i)<k ){
                continue;
            }
            reverse(v[i]);
        }
        ListNode* ans = v[0];
        
        for(int i = 0; i < v.size()-1; i++){
 
            while(v[i]->next!=NULL){
                v[i] = v[i]->next;
            }
            v[i]->next = v[i+1];
        }
        return ans;
    }
};

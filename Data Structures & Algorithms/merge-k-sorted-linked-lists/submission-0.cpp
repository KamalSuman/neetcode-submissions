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
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(0);
        ListNode* head = ans;
        while(list1 != NULL &&  list2 != NULL){
            if(list1->val < list2->val){
                if(ans == NULL) {ans = list1; head = ans;}
                else ans->next = list1;
                list1 = list1->next;
            } else {
                if(ans == NULL) {ans = list2; head = ans;}
                else ans->next = list2;
                list2 = list2->next;
            }
            ans = ans->next;
        }    
        if(list1 != NULL){
            ans->next = list1;  
        } 
        if(list2 != NULL){
            ans -> next = list2;
        }
        ListNode* k = head->next;
        delete head;
        return k;
    }
    ListNode* mergeSortLists(int i, int j, vector<ListNode*> & lists){
        if(i==j) return lists[i];
        int mid = (i + j)/2;
        ListNode* left1 = mergeSortLists(i,mid,lists);
        ListNode* right1 = mergeSortLists(mid+1,j,lists);

        return merge(left1,right1);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        int n = lists.size();
        return mergeSortLists(0,n-1,lists);    
    }
};

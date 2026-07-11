/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* head1 = head;
        Node* ans = new Node(0);
        Node* ans1 = ans;
        Node* ans2 = ans;
        map<Node*,Node*> m;
        while(head != NULL){
            ans->next = new Node(head->val);
            ans = ans->next;
            m[head] = ans;
            head = head->next;
        }
        ans1 = ans1->next;
        while(head1!=NULL){
            Node* tmp = head1->random;
            if(tmp != NULL) ans1->random = m[tmp];
            ans1 = ans1 -> next;
            head1 = head1 -> next;
        }
        ans2 = ans2->next;
        return ans2;
    }
};

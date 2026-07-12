/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        int p1 = p->val;
        int q1 = q->val;
        int r = root->val;
        if(r > p1 && r> q1) return lowestCommonAncestor(root->left,p,q);
        else if(r < p1 && r< q1) return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};

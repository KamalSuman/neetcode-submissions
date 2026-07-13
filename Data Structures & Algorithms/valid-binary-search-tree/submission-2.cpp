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
    bool help(TreeNode* root, int l, int r){
        if(root == NULL) return true;
        if(root->val <= l || root->val >= r) return false;
        return help(root->left,l,root->val) & help(root->right,root->val,r);
    }
    bool isValidBST(TreeNode* root) {
        return help(root,-1001,1001);
    }
};

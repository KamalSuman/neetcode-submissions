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
    int ans = -1;
    void help(TreeNode* root, int& k1, int& k){
        if(root == NULL) return;
        help(root->left, k1, k);
        k1++;
        if(k1== k) {ans = root->val; return;}
        help(root->right,k1,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int k1 = 0;
        help(root,k1, k);
        return ans;
    }
};

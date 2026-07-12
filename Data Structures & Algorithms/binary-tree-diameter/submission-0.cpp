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
    vector<int> h;
    int ans = 0;
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return h[root->val] =  1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    
    int dia(TreeNode* root){
        if(root == NULL) return 0;
        int dl = dia(root->left);
        int dr = dia(root->right);
        int r = 0;
        if(root->left != NULL)r += h[root->left->val];
        if(root->right != NULL) r += h[root->right->val];
        ans = max(ans,max(r,max(dl,dr)));
        return r;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        h.resize(101,0);
        maxDepth(root);
        dia(root);
        return ans;
    }
};

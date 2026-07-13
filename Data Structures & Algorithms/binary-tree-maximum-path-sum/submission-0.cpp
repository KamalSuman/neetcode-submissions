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
    int ans = INT_MIN;
    int help(TreeNode* root){
        if(root == NULL) return INT_MIN;
        int l = help(root->left);
        int r = help(root->right);
        int temp = root->val;
        if(l>0) temp += l;
        if(r>0) temp += r;
        int maxi = max(0,max(l,r));
        ans = max(ans,temp);
        return root->val + maxi;
    }
    int maxPathSum(TreeNode* root) {
        help(root);
        return ans;
    }
};

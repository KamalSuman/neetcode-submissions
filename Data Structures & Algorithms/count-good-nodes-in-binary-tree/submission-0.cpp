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
    int ans(TreeNode* root, int maxi){
        if(root == NULL) return 0;
        int ans1 = root->val >= maxi;
        maxi = max(maxi,root->val);
        return ans1 + ans(root->left,maxi) + ans(root->right,maxi); 

    }
    int goodNodes(TreeNode* root) {
        return ans(root,-101);
    }
};

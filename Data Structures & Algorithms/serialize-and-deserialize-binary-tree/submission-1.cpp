/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>

using namespace std;

class Codec {
public:

    string serialize(TreeNode* root) {
        if(root == NULL) return "[]";
        string s = "[";
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if (node == NULL) {
                s += "null,";
            } else {
                s += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        
        s.pop_back(); 
        s.push_back(']');
        return s;
    }

    TreeNode* deserialize(string data) {
       if(data == "[]") return nullptr;
       int n = data.size();
       
       string temp="";
       vector<string> str;
       for(int i = 1; i<=n-2; i++){
            if(data[i] == ','){
                str.push_back(temp);
                temp = "";
                continue;
            }
            temp += data[i];
       }
       str.push_back(temp);
       queue<TreeNode*> q;
       TreeNode* ans = new TreeNode(stoi(str[0]));
       q.push(ans);
       
       int i = 1;
       while(!q.empty() && i < str.size()){
           TreeNode* root = q.front();
           q.pop();

           if (i < str.size() && str[i] != "null") {
               root->left = new TreeNode(stoi(str[i]));
               q.push(root->left);
           }
           i++; 
           if (i < str.size() && str[i] != "null") {
               root->right = new TreeNode(stoi(str[i]));
               q.push(root->right);
           }
           i++; 
       }
       return ans;
    }
};
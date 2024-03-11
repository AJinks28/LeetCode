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
    void dfs(TreeNode*root, vector<int>&inorder){
        if(!root) return;
        
        if(root->left) dfs(root->left,inorder);
        inorder.push_back(root->val);
        if(root->right) dfs(root->right,inorder);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        if(!root) return inorder;
        dfs(root,inorder);
        return inorder;
    }
};
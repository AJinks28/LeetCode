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
    void dfs(TreeNode*root, vector<int>&postorder){
        if(!root) return;
        
        if(root->left) dfs(root->left,postorder);
        if(root->right) dfs(root->right,postorder);
        postorder.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(!root) return postorder;
        
        dfs(root,postorder);
        return postorder;
    }
};
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
    bool isBST(TreeNode* root,TreeNode* &prev){
        if(!root) return true;
        if(!isBST(root->left,prev)) return false;
        
        if(prev!=NULL && prev->val>=root->val) return false;
        
        prev=root;
        
        return isBST(root->right,prev);
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* prev=NULL;
        return isBST(root,prev);
    }
};
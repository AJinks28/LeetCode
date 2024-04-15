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
    int sum=0;
    void dfs(TreeNode* root,int num){
        if(!root){
            // sum+=num;
            cout<<num<<" ";
            return;
        } 
        
        num=num*10+root->val;
        
        if(!root->left && !root->right){
            sum+=num;
            
            // cout<<num<<" ";
        }
        if(root->left) dfs(root->left,num);
        if(root->right) dfs(root->right,num);
    }
    int sumNumbers(TreeNode* root) {
        // int sum=0;
        int num=0;
        dfs(root,num);
        return sum;
    }
};
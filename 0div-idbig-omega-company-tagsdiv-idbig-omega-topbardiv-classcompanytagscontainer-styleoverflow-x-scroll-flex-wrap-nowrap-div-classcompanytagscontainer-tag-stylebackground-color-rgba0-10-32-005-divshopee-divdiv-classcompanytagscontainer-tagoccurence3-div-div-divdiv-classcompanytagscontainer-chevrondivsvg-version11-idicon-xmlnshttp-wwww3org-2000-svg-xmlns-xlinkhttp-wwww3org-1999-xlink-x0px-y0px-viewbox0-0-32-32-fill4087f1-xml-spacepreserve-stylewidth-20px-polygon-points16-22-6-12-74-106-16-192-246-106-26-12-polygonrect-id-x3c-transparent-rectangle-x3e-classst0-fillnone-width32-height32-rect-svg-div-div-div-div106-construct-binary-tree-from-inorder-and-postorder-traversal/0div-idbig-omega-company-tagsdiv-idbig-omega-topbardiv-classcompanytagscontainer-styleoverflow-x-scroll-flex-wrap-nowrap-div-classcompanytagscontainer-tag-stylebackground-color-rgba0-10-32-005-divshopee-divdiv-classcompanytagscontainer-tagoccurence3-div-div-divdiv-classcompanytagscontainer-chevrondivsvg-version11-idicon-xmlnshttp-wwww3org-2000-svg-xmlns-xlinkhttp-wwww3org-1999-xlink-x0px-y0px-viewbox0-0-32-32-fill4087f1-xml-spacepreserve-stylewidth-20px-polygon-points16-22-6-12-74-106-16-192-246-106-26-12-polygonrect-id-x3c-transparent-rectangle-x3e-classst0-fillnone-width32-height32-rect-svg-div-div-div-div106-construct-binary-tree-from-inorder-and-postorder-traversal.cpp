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
    int postIdx;
    map<int,int> mp;
    
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder,int l,int r){
        if(l>r) return NULL;
        
        int curr=postorder[postIdx];
        int inIdx=mp[curr];
        TreeNode* root=new TreeNode(curr);
        postIdx--;
        
        root->right=solve(postorder,inorder,inIdx+1,r);
        root->left=solve(postorder,inorder,l,inIdx-1);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        postIdx=n-1;
        for(int i=0;i<n;i++) mp[inorder[i]]=i;
        return solve(postorder,inorder,0,n-1);
    }
};
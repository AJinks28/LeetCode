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
//upper bound for left child will be val of curr_node and 
//for right child will be parent_node of curr_node(uppbd in that recursive call)
    TreeNode* solve(vector<int>& preorder,int &ind,int uppbd){
        if(ind==preorder.size() || preorder[ind]>uppbd) return NULL;

        TreeNode* root=new TreeNode(preorder[ind]);
        ind++;
        root->left=solve(preorder,ind,root->val);
        root->right=solve(preorder,ind,uppbd);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind=0;
        return solve(preorder,ind,INT_MAX);
    }
};
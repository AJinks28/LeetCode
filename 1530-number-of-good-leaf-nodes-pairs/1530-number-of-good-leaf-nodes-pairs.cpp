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
    int ans=0;
    //p id distances of all leaf nodes
    vector<int> dfs(TreeNode* root, int d){
        if(!root) return {};
        
        vector<int> p;
        vector<int> left=dfs(root->left,d);
        vector<int> right=dfs(root->right,d);
        
        if(left.size()==0 && right.size()==0){
            p.push_back(1);
            return p;
        }
        
        for(int i=0;i<left.size();i++){
            for(int j=0;j<right.size();j++){
                if(left[i]+right[j]<=d) ans++;
            }
        }
        
        for(int &l:left){ l++; p.push_back(l); }
        for(int &r:right){ r++; p.push_back(r); }
        
        return p;
        
    }
    
    int countPairs(TreeNode* root, int distance) {
        dfs(root,distance);
        return ans;
    }
};
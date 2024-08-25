/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root,map<TreeNode*,TreeNode*> &parent){
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            
            if(curr->left){
                parent[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right]=curr;
                q.push(curr->right);
            }
        }
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        
        map<TreeNode*,TreeNode*> parent;
        markParents(root,parent);
        
        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*,bool> vis;
        vector<int> ans;
        vis[target]=true;
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                TreeNode* curr=q.front();
                q.pop();
                
                if(k==0) ans.push_back(curr->val);
                
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if(parent.find(curr)!=parent.end() && !vis[parent[curr]]) {
                    q.push(parent[curr]);
                    vis[parent[curr]]=true;
                }
            }
            
            k--;
        }
        return ans;
    }
};
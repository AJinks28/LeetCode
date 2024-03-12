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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp; //vert->level->{multiple nodes at that vert & level}
        queue<pair<TreeNode*,pair<int,int>>> q; //{root,{vert,level}}
        vector<vector<int>> ans;
        if(!root) return ans;
        
        q.push({root,{0,0}});
        
        while(!q.empty()){
            TreeNode* curr=q.front().first;
            int vert= q.front().second.first;
            int level=q.front().second.second;
            q.pop();
            
            mp[vert][level].insert(curr->val);
            
            if(curr->left) q.push({curr->left,{vert-1,level+1}});
            if(curr->right) q.push({curr->right,{vert+1,level+1}});
        }
        
        for(auto vertElem:mp){
            vector<int> col;
            for(auto levelElem:vertElem.second){
                col.insert(col.end(),levelElem.second.begin(),levelElem.second.end());
                //this line means insert elements in range [levelElem.second.begin(),levelElem.second.end()]
                //into col starting from col.end()
            }
            ans.push_back(col);
        }
        return ans;
    }
};
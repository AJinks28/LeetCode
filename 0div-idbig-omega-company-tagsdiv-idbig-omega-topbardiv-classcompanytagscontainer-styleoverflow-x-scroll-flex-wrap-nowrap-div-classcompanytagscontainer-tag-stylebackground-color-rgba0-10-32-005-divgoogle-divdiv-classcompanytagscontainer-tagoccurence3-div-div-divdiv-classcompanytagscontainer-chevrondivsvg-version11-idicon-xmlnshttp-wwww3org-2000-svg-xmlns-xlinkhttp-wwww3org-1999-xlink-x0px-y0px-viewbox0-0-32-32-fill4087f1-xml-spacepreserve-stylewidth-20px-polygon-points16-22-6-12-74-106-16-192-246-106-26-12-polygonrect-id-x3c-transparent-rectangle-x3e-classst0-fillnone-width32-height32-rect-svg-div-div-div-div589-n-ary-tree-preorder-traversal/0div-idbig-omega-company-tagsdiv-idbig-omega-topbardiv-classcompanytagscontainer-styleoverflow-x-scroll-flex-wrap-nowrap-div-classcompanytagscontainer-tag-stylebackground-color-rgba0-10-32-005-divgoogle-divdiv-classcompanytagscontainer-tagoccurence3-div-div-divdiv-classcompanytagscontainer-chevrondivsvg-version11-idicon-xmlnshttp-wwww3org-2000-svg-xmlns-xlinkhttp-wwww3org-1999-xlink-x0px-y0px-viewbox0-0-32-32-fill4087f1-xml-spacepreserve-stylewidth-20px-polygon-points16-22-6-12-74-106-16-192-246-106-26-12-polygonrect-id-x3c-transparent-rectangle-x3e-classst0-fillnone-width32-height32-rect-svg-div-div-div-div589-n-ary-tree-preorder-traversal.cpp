/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
     void dfs(Node*root, vector<int>&preorder){
        if(!root) return;
        preorder.push_back(root->val);
        for(auto it:root->children){
            dfs(it,preorder);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> preorder;
        if(!root) return preorder;
        dfs(root,preorder);
        return preorder;
    }
};
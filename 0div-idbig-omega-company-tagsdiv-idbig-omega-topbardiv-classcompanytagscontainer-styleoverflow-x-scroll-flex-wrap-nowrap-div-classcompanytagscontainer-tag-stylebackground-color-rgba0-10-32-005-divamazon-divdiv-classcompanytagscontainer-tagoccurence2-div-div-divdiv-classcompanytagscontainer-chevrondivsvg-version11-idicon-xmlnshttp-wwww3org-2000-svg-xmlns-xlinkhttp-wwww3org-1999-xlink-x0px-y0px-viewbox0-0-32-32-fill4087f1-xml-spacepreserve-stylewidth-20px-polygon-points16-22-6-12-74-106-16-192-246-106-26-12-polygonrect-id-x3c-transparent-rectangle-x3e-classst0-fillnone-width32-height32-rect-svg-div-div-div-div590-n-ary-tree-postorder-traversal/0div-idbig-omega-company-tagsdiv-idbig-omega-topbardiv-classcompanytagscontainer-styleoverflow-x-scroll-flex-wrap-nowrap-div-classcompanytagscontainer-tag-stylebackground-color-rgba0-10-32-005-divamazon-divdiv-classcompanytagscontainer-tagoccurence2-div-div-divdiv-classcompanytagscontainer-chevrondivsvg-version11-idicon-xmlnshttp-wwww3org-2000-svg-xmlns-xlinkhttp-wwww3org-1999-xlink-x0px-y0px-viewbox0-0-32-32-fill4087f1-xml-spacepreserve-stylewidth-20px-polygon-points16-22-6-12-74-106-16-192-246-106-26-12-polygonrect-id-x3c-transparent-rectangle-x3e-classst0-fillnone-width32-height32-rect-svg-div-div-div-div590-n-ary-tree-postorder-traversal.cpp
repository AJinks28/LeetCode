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
    void dfs(Node*root, vector<int>&postorder){
        if(!root) return;
        
        for(auto it:root->children){
            dfs(it,postorder);
        }
        postorder.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> postorder;
        if(!root) return postorder;
        dfs(root,postorder);
        return postorder;
    }
};
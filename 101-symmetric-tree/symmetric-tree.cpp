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
    bool isSymmetric(TreeNode* root) {
     if(root==NULL) return false;
     queue<TreeNode*>q;
     q.push(root->left);
     q.push(root->right);
     while(!q.empty()){
        TreeNode* a=q.front();
        q.pop();
        TreeNode* b=q.front();
        q.pop();
        if(a==NULL&& b==NULL) continue;
        if(a==NULL||b==NULL) return false;
        if(a->val!=b->val) return false;
        q.push(a->left);
        q.push(b->right);
        q.push(a->right);
        q.push(b->left);

     }  
     return true; 
    }
};
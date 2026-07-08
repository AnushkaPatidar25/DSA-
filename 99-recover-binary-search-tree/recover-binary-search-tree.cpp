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
    void inorder(TreeNode* root,vector<int>&ans){
        if(root==NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    void solve(TreeNode* root,int bada,int chota){
        if(root==NULL) return ;
        if(root->val==bada) root->val=chota;
        else if(root->val==chota) root->val=bada;
        solve(root->left,bada,chota);
        solve(root->right,bada,chota);
    }
     void recoverTree(TreeNode* root) {
     vector<int>ans;
     inorder(root,ans); 
     vector<int>res=ans;
     sort(res.begin(),res.end());
     int bada =-1,chota=-1;
     for(int i=0;i<ans.size();i++){
        if(ans[i]!=res[i]){
            if(bada==-1) bada=ans[i];
            else chota=ans[i];
        }
     }
       solve(root,bada,chota); 
    }
};
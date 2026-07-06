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
   TreeNode* mini(TreeNode* root){
    if(root==NULL) return NULL;
    TreeNode* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
  }
  TreeNode* del(TreeNode* root,int key){
    if(root==NULL) return NULL;
    if(root->val==key){
    if(root->left==NULL && root->right==NULL){
        delete root;
        return NULL;
    }
    else if(root->left!=NULL && root->right==NULL){
        TreeNode* temp=root->left;
        delete root;
        return temp;
    }
   else  if(root->left==NULL && root->right!=NULL){
        TreeNode* temp=root->right;
        delete root;
        return temp;
    }
    else if(root->left!=NULL && root->right!=NULL ){
        int ans=mini(root->right)->val;
        root->val=ans;
        root->right=del(root->right,ans);
       return root;
    }
    }
    else if (root->val>key){
        root->left=del(root->left,key);
        return root;
    }
    else{
        root->right=del(root->right,key);
        return root;
    }
    return root;
  }
    TreeNode* deleteNode(TreeNode* root, int key) {
       TreeNode*ans= del(root,key);
      return ans; 
    }
};
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
int height(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    int ans=max(left,right)+1;
    return ans;
}
    bool isBalanced(TreeNode* root) {
       if(root==NULL) {
        return true;
       }
       bool op1=isBalanced(root->left);
       bool op2=isBalanced(root->right);
       int left=height(root->left);
       int right=height(root->right);
       bool ans=abs(left-right)<= 1;
       if(ans&op1&op2){
        return true;
       }
       else{
        return false;
       }
    }
};
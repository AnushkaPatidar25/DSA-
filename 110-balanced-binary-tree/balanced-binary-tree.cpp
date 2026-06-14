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
    pair<bool,int> isBalancedFast(TreeNode* root) {
       if(root==NULL) {
        pair<bool,int>p=make_pair(true,0);
        return p;
       }
       pair<bool,int> op1=isBalancedFast(root->left);
       pair<bool,int> op2=isBalancedFast(root->right);
       bool left=op1.first;
       bool right=op2.first;
       bool op3=abs(op1.second-op2.second)<= 1;
       pair<bool,int>ans;
       ans.second=max(op1.second,op2.second)+1;
       if(op3&left& right){
        ans.first= true;
       }
       else{
        ans.first= false;
       }
       return ans;
    }
    bool isBalanced(TreeNode* root){
        return isBalancedFast(root).first;
    }
};
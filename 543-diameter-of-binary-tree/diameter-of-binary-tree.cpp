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
pair<int,int>diamter(TreeNode* root){ 
    if(root==NULL){
        pair<int,int>p=make_pair(-1,-1);
        return p;
    }
    pair<int,int>left=diamter(root->left);
    pair<int,int>right=diamter(root->right);
    pair<int,int>ans;
    ans.second=max(left.second,right.second)+1;
    int op1=left.first;
    int op2=right.first;
    int op3=left.second+2+right.second;
     int res=max(op1,max(op2,op3));
     ans.first=res;
      return ans;
}
    int diameterOfBinaryTree(TreeNode* root) {
      return diamter(root).first;
    }
};
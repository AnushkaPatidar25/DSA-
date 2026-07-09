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
  int maxi;
  int mini;
  bool isBST;
  int sum;
   Solution solve(TreeNode* root,int &sum){
   if(root==NULL) return{INT_MIN,INT_MAX,true,0};
   Solution left=solve(root->left,sum);
   Solution right=solve(root->right,sum);
    Solution currNode;
    currNode.maxi=max(root->val,right.maxi);
    currNode.mini=min(root->val,left.mini);
    currNode.sum=left.sum+right.sum+root->val;
   if(left.isBST && right.isBST && (root->val>left.maxi && root->val<right.mini)){
    currNode.isBST=true;
   }
   else{
    currNode.isBST=false;
   }
   if(currNode.isBST){
    sum=max(sum,currNode.sum);
   }
   return currNode;
  }
    int maxSumBST(TreeNode* root) {
       int sum=0;
       Solution temp=solve(root,sum); 
       return sum;
    }
};
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
void createmapping(vector<int>&inorder,map<int,int>&mp){
    for(int i=0;i<inorder.size();i++){
        mp[inorder[i]]=i;
    }
}
 TreeNode* build(vector<int>&inorder,vector<int>&preorder,map<int,int>&mp,int &preindex,int inorderstarting,int inorderending,int n){
    if(preindex>=n || inorderstarting>inorderending) return NULL;
      int element=preorder[preindex++];
        TreeNode*node=new TreeNode(element);
        int position=mp[element];
      node->left=build(inorder,preorder,mp,preindex,inorderstarting,position-1,n);
      node->right=build(inorder,preorder,mp,preindex,position+1,inorderending,n);
      return node;
    
 }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       map<int,int>mp;
       createmapping(inorder,mp);
       int preindex=0;
       int n=inorder.size();
        TreeNode* ans = build(inorder,preorder,mp,preindex,0,n-1, n);
        return ans;
    }
};
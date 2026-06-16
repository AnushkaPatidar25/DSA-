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
   TreeNode* build(vector<int>&inorder,vector<int>&postorder,int &postindex,int inorderstarting,int inoderending,int n,map<int,int>&mp ){
    if(postindex<0||inorderstarting>inoderending)return NULL;
    int element=postorder[postindex--];
    TreeNode* node=new TreeNode(element);
    int pos=mp[element];
   node->right=build(inorder,postorder,postindex,pos+1,inoderending,n,mp);
    node->left=build(inorder,postorder,postindex,inorderstarting,pos-1,n,mp);
  
    return node;
   }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
     map<int,int>mp;
     createmapping(inorder,mp);
     int n=inorder.size();
     int postindex=postorder.size()-1;
     TreeNode* ans=build(inorder,postorder,postindex,0,n-1,n,mp); 
     return ans;  
    }
};
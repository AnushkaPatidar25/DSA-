/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
 bool solve(TreeNode* root,vector<TreeNode*>&path,TreeNode* target){
    if(root==NULL) return false ;
      path.push_back(root);
      if(root==target) return true;
    if(solve(root->left,path,target)||
    solve(root->right,path,target)) return true;
    path.pop_back();
    return false;
 
}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     vector<TreeNode*>path1;
     vector<TreeNode*>path2;
     solve(root,path1,p);
     solve(root,path2,q);
      int i=path1.size()-1;
      int j=path2.size()-1;
      while(i>=0&& j>=0){
        if(path1[i]==path2[j])
         return path1[i];
        if(i>j) i--;
        else j--;
      }
      return NULL;
    }
};
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
    int widthOfBinaryTree(TreeNode* root) {
      int maxwidth=0;
      if(root==NULL) return 0;
      queue<pair<TreeNode*,int>>q;
      q.push(make_pair(root,0));
      while(!q.empty()){
        int size=q.size();
        long long first=0,last=0;
        long long mini=q.front().second;
        for(int i=0;i<size;i++){
        pair<TreeNode*,int> front=q.front();
        q.pop();
        TreeNode* node=front.first;
        long long index=front.second-mini;
       
        if(i==0){ 
            first=index;
            }
        if(i==size-1) {last=index;}
        if(node->left){
            q.push(make_pair(node->left,2*index+1));
        }
        if(node->right){
            q.push(make_pair(node->right,2*index+2));
        }
        }
        if(maxwidth<last-first+1){
            maxwidth=last-first+1;
        }
        }
      
      return maxwidth;
    }
};
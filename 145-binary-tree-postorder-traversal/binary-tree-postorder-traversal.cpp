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
    vector<int> postorderTraversal(TreeNode* root) {
      vector<int>ans;
      if(root==NULL) return ans;
      stack<TreeNode*> s1;
      stack<TreeNode*>s2;
     s1.push(root);
     while(!s1.empty()){
        TreeNode* front=s1.top();
        s1.pop();
        if(front->left){
            s1.push(front->left);
        }
        if(front->right){
            s1.push(front->right);
        }
        s2.push(front);
     }
      while(!s2.empty()){
        TreeNode* node=s2.top();
        s2.pop();
        ans.push_back(node->val);
      }
    
      return ans;
    }
};
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
      stack<TreeNode*> s1;
      TreeNode* node=root;
      TreeNode* lastvisited=NULL;
     while(true){
        if(node!=NULL){
            s1.push(node);
            node=node->left;
        }
        else{
            if(s1.empty())break;
            TreeNode* top=s1.top();
            
            if(top->right!=NULL && lastvisited!=top->right){
               
                node=top->right;
                
            }
            else{
                ans.push_back(top->val);
                lastvisited=top;
                s1.pop();
            }
        }
     }
      return ans;
    }
}; 
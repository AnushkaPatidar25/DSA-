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
void createmapping(TreeNode* root,map<TreeNode*,TreeNode*>&mp){
    if(root==NULL) return;
    queue<TreeNode*>q;
    q.push(root);
    mp[root]=NULL;
    while(!q.empty()){
        TreeNode* front=q.front();
        q.pop();
        if(front->left){
            q.push(front->left);
            mp[front->left]=front;
        }
        if(front->right){
            q.push(front->right);
            mp[front->right]=front;
        }
    }
}
  void distance(TreeNode* root,TreeNode* target,int k ,vector<int>&ans,map<TreeNode*,TreeNode*>&mp){
   map<TreeNode*,bool>vist;
   queue<TreeNode*>q;
   q.push(target);
   vist[target]=true;
   int dist=0;
   while(!q.empty()){
   int size=q.size();
    if(dist==k) break;
   dist++;
    for(int i=0;i<size;i++){
      TreeNode* front=q.front();
      q.pop();
      if(front->left&&!vist[front->left]){
        q.push(front->left);
        vist[front->left]=true;
      }
      if(front->right&&!vist[front->right]){
        q.push(front->right);
        vist[front->right]=true;
      }
      if(mp[front]&&!vist[mp[front]]){
       q.push(mp[front]);
       vist[mp[front]]=true;
      }
    }
   }
   while(!q.empty()){
    TreeNode* res=q.front();
    ans.push_back(res->val);
    q.pop();
   }
  }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
     map<TreeNode*,TreeNode*>mp;
     createmapping(root,mp); 
     vector<int>ans;
     distance(root,target,k,ans,mp);
     return ans; 
    }
};
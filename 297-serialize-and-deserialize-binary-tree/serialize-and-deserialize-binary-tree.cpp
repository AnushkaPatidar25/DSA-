/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      string st="";
      if(root==NULL) return "";
      queue<TreeNode*>q;
      q.push(root);
      while(!q.empty()){
        TreeNode* front=q.front();
        q.pop();
        if(front==NULL){
            st+="null,";
            continue;
        }
 
        st+=to_string(front->val);
        st+=",";
        q.push(front->left);
        q.push(front->right);
      } 
      return st;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        vector<string>token;
        string temp="";
        for(char ch : data){
            if(ch==','){
                token.push_back(temp);
                temp="";
            }
            else{
                temp+=ch;
            }
        }
        token.push_back(temp);
        TreeNode* root=new TreeNode(stoi(token[0]));
        queue<TreeNode*>q;
        q.push(root);
        int i=1;
        while(!q.empty() && i<token.size()){
            TreeNode* front=q.front();
            q.pop();
            if(token[i]!="null"){
             front->left=new TreeNode(stoi(token[i]));
             q.push(front->left);
            }
            i++;
            if(i<token.size()&&token[i]!="null"){
                front->right=new TreeNode(stoi(token[i]));
                q.push(front->right);           
          }
          i++;
        }
       
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
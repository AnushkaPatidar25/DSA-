    /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false);
    }

private:
    int helper(TreeNode* node, bool isLeft) {
        if (!node)
            return 0;
        
        if (!node->left && !node->right) {
            if (isLeft)
                return node->val;
            else
                return 0;
        }
             return helper(node->left, true) + helper(node->right, false);
    }
};


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
    bool recur(TreeNode* root){

        if(root->left == NULL && root->right == NULL) return root->val;

        bool left = recur(root->left);
        bool right = recur(root->right);

        if(root->val == 2) return left | right;
        else  return left & right;

    }
    bool evaluateTree(TreeNode* root) {
        return recur(root);
    }
};
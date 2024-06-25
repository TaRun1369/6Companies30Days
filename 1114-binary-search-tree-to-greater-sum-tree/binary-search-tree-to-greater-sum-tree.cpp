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
int maxi = 0;
    void helper(TreeNode* node){
        if(node == NULL) return;
        

        helper(node->right);
        maxi += node->val;
        node->val = maxi;
       
         helper(node->left);

        // return maxi;
    }
    TreeNode* bstToGst(TreeNode* root) {
         helper(root);
        return root;
    }
};
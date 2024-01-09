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
    void func(TreeNode* root,vector<int> &v){
        if(root == NULL) return;

        if(root->left == NULL && root->right == NULL){
            v.push_back(root->val);
        }

        func(root->left,v);
        func(root->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> one,two;
        func(root1,one);
        func(root2,two);
        if(one == two) return true;
        return false;
    }
};
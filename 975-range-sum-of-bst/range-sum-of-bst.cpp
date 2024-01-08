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
    int summ(int low,int high,TreeNode* curr){
        if(curr == NULL) {
            return 0;
        }
        int right = 0;
        int left = 0;
        if(curr->val < low){
            right = summ(low,high,curr->right);
        }
        else if(curr->val > high){
            left = summ(low,high,curr->left);
        }
        else{
            left = curr->val + summ(low,high,curr->left);
            right = summ(low,high,curr->right);

        }

        return  left + right;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return summ(low,high,root);

    }
};
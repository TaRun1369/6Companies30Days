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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(key < root->val){
            root->left = deleteNode(root->left,key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right,key);
        }
        else{
            if(root->left == NULL && root->right == NULL){
                return NULL;
            }
            else if(root->right == NULL && root->left != NULL){
                // left bacha hai 
                TreeNode* temp = root->left;
                while(temp->right){
                    temp = temp->right;
                }
                root->val = temp->val;
                root->left = deleteNode(root->left,root->val);
            }
            else {
                TreeNode* temp = root->right;
                while(temp->left){
                    temp = temp->left;
                }
                root->val = temp->val;
                root->right = deleteNode(root->right,root->val);
            }
        }
        return root;
    }
};
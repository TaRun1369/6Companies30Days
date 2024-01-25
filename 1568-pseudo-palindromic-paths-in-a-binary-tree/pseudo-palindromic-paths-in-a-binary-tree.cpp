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
    // time/space: O(n)/O(h)
    int pseudoPalindromicPaths (TreeNode* root) {
        // terminate
        if (root == NULL) return 0;
        
        // update the count
        count[root->val]++;

        // check the pseudo-palindromic for the leaf node
        int value = 0;
        if ((root->left == NULL) && (root->right == NULL)) {
            if (check()) value = 1;
            else value = 0;
        }
        else {
            // recursive
            value = pseudoPalindromicPaths(root->left) + pseudoPalindromicPaths(root->right);
        }

        // revert the count
        count[root->val]--;

        return value;
    }
private:
    int count[10] = {0};
    bool check(void) {
        int oddCount = 0;
        for (int i = 1; i <= 9; i++) {
            if ((count[i] & 1) == 1) oddCount++;
        }
        return (oddCount <= 1);
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    void deleteNode(ListNode* node) {
        int val = node->val;
        ListNode* prev = node;
        while(node->next  != NULL){
            node->val = node->next->val;
            // if (node->next->next == NULL) break;
            prev = node;
            node = node->next;
        }
        cout<<node->val<<endl;
        prev->next = NULL; 
        
    }
};
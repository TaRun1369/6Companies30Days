/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* reverse(ListNode* head){
        ListNode* dum = NULL,*temp = head;
        while(temp != NULL){
            ListNode* nex = temp->next;
            temp->next = dum;
            dum = temp;
            temp = nex;
        }
        return dum;
    }
    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);
        ListNode* temp = head;
        int carry = 0;
        while(temp != NULL){
            int sum = 2*(temp->val) +carry;
             carry = sum/10;

            temp->val = sum%10;
            temp = temp->next;
        }
        head = reverse(head);
        if(carry > 0){
            ListNode* nN = new ListNode(carry);
            nN->next = head;
            head =  nN;
        }
        
        
       
        return head;
    }

};
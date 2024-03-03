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
        ListNode* temp = head,*dum = NULL,*nex;

        while(temp != NULL ){
            nex = temp->next;
            temp->next = dum;
            dum = temp;
            temp = nex;
            if(nex != NULL)
            nex = nex->next;

        }
        // head = dum;
    return dum;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = reverse(head);

        
        ListNode* temp = head,*prev = NULL;
        // while(temp != NULL){
        //     cout<<temp->val<<endl;
        //     temp = temp->next;
        // }
        int c = 1;
        while(temp != NULL){
            if(c == n){
                // cout<<"yaha"<<endl;
                if(temp != head)
                prev->next = temp->next;
                else head = head->next;
                break;    
            }
            prev = temp;
            temp = temp->next;
            c++;
        }
        head = reverse(head);
        return head;
    }
};
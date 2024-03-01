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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        if(head->next == NULL)return NULL;
        ListNode *slow = head->next,*fast = head->next->next,*t = head;
        // bool f = false;
        while(fast != NULL && slow != NULL && fast->next != NULL ){
            if( slow == fast) {
                // f = true;
               while(t != slow){
                   t = t->next;
                   slow = slow->next;
                    }
               return t;
            }
            slow = slow->next;
            fast = fast->next->next;
            
        }
        
        

        // ListNode* t = head;
        // int cnt = 1;
        // while(t!= temp){

        //     t = t->next;
        //     cnt++;
        // }
        return NULL;




    }
};
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
        ListNode* dummy = NULL, *ne , *temp = head;

        while(temp){
            ne = temp->next;
            temp->next = dummy;
            dummy = temp;
            temp = ne;
        }

        return dummy;


    }
    void reorderList(ListNode* head) {
        // head = reverse(head);
        // ListNode* t = head;
        // while(t){
        //     cout<<t->val<<endl;
        //     t = t->next;
        // }

        ListNode* slow = head,*fast = head;
        while(fast->next && fast->next->next){
            // prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // cout<<slow->val<<endl;
        ListNode *aage  = reverse(slow->next);
        slow ->next = NULL;
        // cout<<prev->next->val<<endl;
        // ListNode* t = head;
        // while(t){
        //     cout<<t->val<<endl;
        //     t = t->next;
        // }

        ListNode*temp = head;
        // cout<<aage->val<<endl;

        // int value = aage->val;
        while(aage != NULL){
            
            ListNode* sav = temp->next;
            ListNode* last = aage->next;
            // cout<<"save = "<<sav->val<<endl;
            // cout<<"temp - "<<temp->val<<endl;
            temp->next= aage;
            aage->next = sav;
            temp = sav;
            aage = last;

            // cout<<"save = "<<sav->val<<endl;
            // cout<<"temp - "<<temp->val<<endl;
            // cout<<"last - "<<last->val<<endl;
            // cout<<"aage - "<<aage->val<<endl;
        
        }

        // if(temp != NULL){
        //     aage->next = temp;
        // }
        // if(last != NULL){
        //     aage->next = last;
        // }
    }
};
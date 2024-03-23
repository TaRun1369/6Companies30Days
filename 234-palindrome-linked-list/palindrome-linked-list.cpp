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

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head,*fast = head;
        while(fast->next && fast->next->next){
            // prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }  
        ListNode * t2 = reverse(slow->next),*t1 = head;
        slow->next = NULL;
        while(t2 != NULL && t1 != NULL){
            cout<<"t1 - "<<t1->val<<"t2  - "<<t2->val<<endl;
            if(t1->val != t2->val) return false;
            t1 = t1->next;
            t2 = t2->next;
        }
        return true;

    }
};
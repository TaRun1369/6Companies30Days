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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next;
        ListNode* h = NULL;
        ListNode* nh;
        while(temp != NULL){
            
            int sum = 0;
            while(temp!= NULL &&  temp->val != 0){
                // cout<<"val - "<<temp->val<<endl;
                sum +=temp->val;
                temp = temp->next;
            }
            if(sum != 0){
                ListNode* nn = new ListNode(sum);
                if(h == NULL){
                    h = nn;
                    nh = h;
                }
                else{ h->next = nn;
                // cout<<"nn - "<<h->next->val<<endl;
                h = h->next;}
            }
            temp = temp->next;
        }
        return nh;
    }
};
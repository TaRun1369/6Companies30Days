// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* reverse(ListNode* head){
//         ListNode* dummy = NULL, *ne , *temp = head;

//         while(temp){
//             ne = temp->next;
//             temp->next = dummy;
//             dummy = temp;
//             temp = ne;
//         }

//         return dummy;


//     }
//     void reorderList(ListNode* head) {
//         // head = reverse(head);
//         // ListNode* t = head;
//         // while(t){
//         //     cout<<t->val<<endl;
//         //     t = t->next;
//         // }

//         ListNode* slow = head,*fast = head,*prev = head;
//         while(fast && fast->next){
//             prev = slow;
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         // cout<<slow->val<<endl;
//         prev->next = reverse(prev->next);
//         // cout<<prev->next->val<<endl;
//         // ListNode* t = head;
//         // while(t){
//         //     cout<<t->val<<endl;
//         //     t = t->next;
//         // }

//         ListNode* sav,*temp = head,*aage = prev->next,*last;
//         // cout<<aage->val<<endl;

//         // int value = aage->val;
//         while(temp!= NULL && aage != NULL){
            
//             sav = temp->next;
//             // cout<<"save = "<<sav->val<<endl;
//             // cout<<"temp - "<<temp->val<<endl;
//             temp->next= aage;
//             temp = sav;
//             last = aage->next;
//             // if(temp != NULL)
//             aage->next = temp;
//             // if(aage->next != NULL)
//             // aage = aage->next->next;
//             // if(last != NULL)
//             aage = last;

//             cout<<"save = "<<sav->val<<endl;
//             cout<<"temp - "<<temp->val<<endl;
//             cout<<"last - "<<last->val<<endl;
//             cout<<"aage - "<<aage->val<<endl;
        
//         }

//         // if(temp != NULL){
//         //     aage->next = temp;
//         // }
//         // if(last != NULL){
//         //     aage->next = last;
//         // }
//     }
// };

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;
        
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
    }
    
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return;
        
        // Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reverse the second half of the list
        ListNode* secondHalf = reverse(slow->next);
        slow->next = nullptr; // break the original list
        
        // Merge the first and reversed second halves alternatively
        ListNode* firstHalf = head;
        while (secondHalf != nullptr) {
            ListNode* temp1 = firstHalf->next;
            ListNode* temp2 = secondHalf->next;
            firstHalf->next = secondHalf;
            secondHalf->next = temp1;
            firstHalf = temp1;
            secondHalf = temp2;
        }
    }
};

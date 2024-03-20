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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* dummy = new ListNode(0,list1),* temp = list1,*awala,*bwala,*t2 = list2;
        int c = 1;
        while(temp != NULL && c != a){
            temp = temp->next;
            c++;
        }
        awala = temp;
        cout<<awala->val<<endl;

        while(temp != NULL && c != b){
            temp = temp->next;
            c++;
        }
        bwala = temp->next;
        cout<<bwala->val<<endl;

        awala->next = list2;
        
        while(t2->next != NULL){
            t2 = t2->next;
        }
        t2->next = bwala->next;

        return list1;

    }
};
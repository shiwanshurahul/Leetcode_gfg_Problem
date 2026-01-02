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
    ListNode* oddEvenList(ListNode* head) {

     if(head==NULL)
     return NULL;
     
     ListNode * odd =head;
     ListNode * even =head->next;
     ListNode * even_start =even;
        while(odd->next!=NULL && even->next!=NULL){
            odd->next =even->next;//connect all odds: 1->3;3->5;
            cout<<odd->val; //1;3
            even->next = even->next->next;// odd ke v next->next pe kra skte connect all evens: 2->4;        
            odd =odd->next;//3;
            even =even->next;//4
        }
        odd->next =even_start; //5->2;
        return head; 
    }
};
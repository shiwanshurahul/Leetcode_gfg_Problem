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
public:  //LHS lagado/point krado RHS pe
    ListNode* oddEvenList(ListNode* head) {

        if(head==NULL)
            return NULL;
     
        ListNode * odd = head; //1
        ListNode * even = head->next; //2
        ListNode * even_start = even;  //2 -> keep track

        while(odd->next!=NULL && even->next!=NULL){
            odd->next =even->next;//connect all odds: 1->3;3->5;
            odd = odd->next;//3; 5;
            even->next = even->next->next;// or odd ke next-> pe kra skte connect all evens: 2->4;        
            even = even->next; //4
        }
        odd->next = even_start; //5->2;
        return head; 
    }
};
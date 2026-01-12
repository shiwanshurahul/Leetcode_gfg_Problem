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
    ListNode * reverse(ListNode * l1){
       if(l1==NULL || l1->next==NULL)
           return NULL;
        ListNode *curr=l1;
        ListNode *prev =NULL;
        ListNode * next =NULL;
        while(curr!=NULL){
            next =curr->next;
            curr->next =prev;
            prev = curr;
            curr =next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //    l1 =reverse(l1);
      //  l2 =reverse(l2);
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        int carry=0;  //carry forward hota
        while(l1!= NULL || l2!= NULL || carry!=0){
            int sum=0;   //har iteration ka
            if(l1!=NULL){
                sum =sum +l1->val;
                l1 =l1->next;
            }
            if(l2!=NULL){
                sum =sum +l2->val;
                l2 =l2->next;
            }
            sum = sum +carry;
            carry = sum/10;
            ListNode* temp2 = new ListNode(sum%10);
            temp->next =temp2;
            temp = temp->next;
        }
        // dummy =reverse(dummy->next);
       return dummy->next; 
    }
};
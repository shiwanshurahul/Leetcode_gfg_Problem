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
    ListNode *reverse_ll(ListNode * head){
        if(head==NULL)
            return NULL;

        ListNode * curr = head;
        ListNode * prev = NULL;
        ListNode * next = NULL;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        //reverse after middle: 1->2->4->3->x
       
        if(head==NULL)
            return;

        //find middle of ll
        ListNode *slow = head;
        ListNode * fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        } //slow = 3
        //reverse the second half  //3->4->x
        ListNode * rev = reverse_ll(slow);  //4->3->x
        //merge the both ll in asked order
        ListNode * curr = head;  //1->2->4->3->x
        while(rev->next !=NULL){
            ListNode * temp_c = curr->next;  //2  ->pointer rkhne ko
            curr->next = rev;  //1->4

            ListNode * temp_r = rev->next;  //3
            rev->next = temp_c;  //4->2

            curr = temp_c;  //2
            rev = temp_r;    //3
        }

    }//while(rev !=NULL){ //1,4 ; 2,3 -> original ko modify ni krna
    //         temp->next = curr;
    //         temp = temp->next; //or temp=curr;
    //         temp->next = rev;
    //         temp = temp->next;

    //         curr = curr->next;  //2
    //         rev = rev->next;    //3
    //     }
    //     head = dummy->next;
};
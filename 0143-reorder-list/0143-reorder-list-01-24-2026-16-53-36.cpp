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
        //temp = curr->next; //to keep track  //2
        //curr->next pe rev  //1->4
        //rev->next = temp;  //4->2 = 1->4->2
        //curr = temp
        if(head==NULL)
            return;

        //find middle of ll
        ListNode *slow = head;
        ListNode * fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        //reverse the second half  //3->4->x
        ListNode * rev = reverse_ll(slow);
        ListNode * curr = head;
        while(rev->next !=NULL){
            ListNode * temp_c = curr->next;
            curr->next = rev;

            ListNode * temp_r = rev->next;
            rev->next = temp_c;

            curr = temp_c;
            rev = temp_r; 
        }

    }
};
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // brute forc -> 2 lop -> 1st me cnt the len and 2nd me n se pehle ko
        // point kra do next pe
        if(head==NULL)
            return head;
        ListNode* dummy = new ListNode();
        dummy->next =head;
            
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        int k = n;
        while(k--){
            fast =fast->next; //1, 2
        }
        while(fast->next !=NULL){
            fast = fast->next; // 3,4,5
            slow = slow->next; // 1,2,3
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};
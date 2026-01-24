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
ListNode * reverse_ll(ListNode * head){
    if(head==NULL)
        return head;

    ListNode * curr = head;
    ListNode * prev = NULL;
    ListNode * next = NULL;

    while(curr !=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
    bool isPalindrome(ListNode* head) {
        if(head==NULL)
            return true;

        ListNode * fast = head;
        ListNode * slow = head;
        while(fast!=NULL && fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode * rev_head = reverse_ll(slow);
        ListNode * curr = head;
        while(rev_head!=NULL){
            if(rev_head->val!= curr->val)
                return false;

            rev_head = rev_head->next;
            curr = curr->next;    
        }
        return true;

    }
};
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
    ListNode* deleteDuplicates(ListNode* head) {
        //sirf distinct 
         ListNode* dummy = new ListNode(-1);
         ListNode* prev = dummy;
         ListNode* curr = head;
        
        while(curr !=NULL){
            if(curr->next!= NULL && curr->val ==curr->next->val){
                while(curr->next !=NULL && curr->val ==curr->next->val){
                    curr = curr->next;
                }  //curr last duplicat ko point kr rha
                prev->next = curr->next;  //since, curr still duplic pe hai
            } //alag hai curr and curr->next
            else{
                prev->next = curr;  //1->2->4
                prev = prev->next; 
            }
            cout<<prev->val;
            curr = curr->next;
        }
        return dummy->next;
    }
};
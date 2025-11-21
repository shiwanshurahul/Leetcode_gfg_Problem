/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //pehle create normal list with same values
        //same ll ko clone toh same set of random
        if(head==NULL)
            return head;
        Node * curr = head;  //for input ll
        Node *dummy = new Node(-1);   //for o/p ll
        Node *prev = dummy;  //isse hi iterate krenge o/p ll pe  

        unordered_map<Node*, Node*>mp;  //both the ll
        while(curr!=NULL){
            Node *temp =new Node(curr->val);//same val node har bar
            mp[curr] = temp;   //7->7,13->13,11->11,10->10,1->1;
            prev->next =temp;
            prev =temp; //or prev =prev->next
            curr=curr->next;
        }
        //random pointer ka khel
        curr =head;
        Node * newcurr = dummy->next;   //dusra cloned ll
        while(curr){
            if(curr->random==NULL){
                newcurr->random =NULL; 
            }
            else{
                newcurr->random =mp[curr->random];
            }
            curr =curr->next;
            newcurr =newcurr->next;
        }
        return dummy->next;

    //5 3 2 1 3 4   ->n=6
    //slow->5 3 2 1 3 4 5   fast->5 2 3 5 2 1 4
    }
};
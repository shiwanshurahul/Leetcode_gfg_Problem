//{ Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


/*No creating extra linked list 

 //recursion
Node* merge(Node* head1, Node* head2){
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    
    if(head1->data <=head2->data){
        head1->next =merge(head1->next,head2);  
        return head1;
    }
    else{
        head2->next =merge(head1,head2->next);
        return head2;
    }
    return NULL;
}
Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
     return merge(head1,head2);
}  
*/

//iterativel

Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
      if(head1==NULL) return head2;
      if(head2==NULL) return head1;
      Node * ans;
      Node * tail;
     if(head1->data <=head2->data){
     ans =head1;
     tail =head1;
         head1 =head1->next;
     }
    else{
     ans =head2;
     tail =head2;
     head2 =head2->next;
    }
    //merge
    
    while(head1 !=NULL && head2!=NULL){
         if(head1->data <=head2->data){
         tail->next =head1;
         tail =head1;     //or tail =tail->next;
         head1 =head1->next;
         }
         else{
          tail->next =head2;
         tail =head2;     //or tail =tail->next;
         head2 =head2->next;   
         }
    }
    if(head1==NULL)
        tail->next =head2;
      else
        tail->next =head1;
        return ans;
    }
  




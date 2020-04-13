#include<iostream>
#include<stdio.h>
#include<set>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
int intersectPoint(struct Node* head1, struct Node* head2);
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
/* Driver program to test above function*/
int main()
{
    int T,i,n1, n2, n3,l,k;
    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        struct Node *head1 = NULL,  *tail1 = NULL;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        struct Node *head2 = NULL,  *tail2 = NULL;
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        struct Node *head3 = NULL,  *tail3 = NULL;
        for(i=1; i<=n3; i++)
        {
            cin>>l;
            append(&head3, &tail3, l);
        }
        if (tail1 != NULL)
        tail1->next = head3;
        if (tail2 != NULL)
        tail2->next = head3;
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}


/*This is a function problem.You only need to complete the function given below*/
/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */
/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
 int intersectPoint(Node* head1, Node* head2)
{
   Node *temp = head1, *temp2 = head2;
   set<struct Node*> s;
   while(temp != NULL){
       s.insert(temp);
       temp = temp -> next;
   }

   temp = head1;
   int i = 0;
   while(temp2){
       if(s.find(temp2) != s.end()){
           return temp2 -> data;
       }
       else  
       { //s.insert(temp2);
        temp2 = temp2 -> next;
       }
   }
}

// int intersectPoint(Node* head1, Node* head2)
// {
// // Your Code Here
// set<struct Node*> s;
// struct Node * h1 = head1;
// struct Node * h2 = head2;
// struct Node * found;
// while(h1){
//   s.insert(h1);
//   h1=h1->next;
// }
// while(h2){
//   if(s.find(h2)!=s.end()){
//   found = h2;
//   break;
// }
// else{
//   s.insert(h2);
//   h2=h2->next;
// }
// }
// return found->data;
// }
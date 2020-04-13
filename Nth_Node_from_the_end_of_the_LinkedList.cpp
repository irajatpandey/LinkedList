#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *head = NULL;
    Node *createNode(){
        Node *temp = new Node();
        return temp;
    }

    void insertNodeAtBeginning(int); 
    void insertNodeAtEnd(int);
    Node *reverseList_BruteForce(Node *);
    Node *merge(Node *head1, Node *head2);
    
    void display();
    int getNthFromLast(Node*, int); 
    
    void setHead(Node *newHead){
        head = newHead;
    }
    Node *returnHead(){
        return head;
    }
};    
/* Approach getNthFromLast */
/* traverse through len - n + 1 */
/* int Node :: getNthFromLast(Node *head, int n){
      Node *temp = head;
        int len = 0;
        while(temp != NULL){
            temp = temp -> next;
            len++;
        }
        temp = head;
        if(len < n) return -1;
       len = len - n + 1;
       
       for(int i = 1; i < (len); i++){
           temp = temp -> next;
       }
       
       
       return (temp -> data);
      
} */

// Two Pointer Approach
int Node :: getNthFromLast(Node *head, int n){
    Node *mainPtr = head;
    Node *refPtr =  head;
    int count = 0;
    if(head != NULL){
    while(count < n){
        if(refPtr == NULL)
            return -1;
        refPtr = refPtr -> next;
        count++;
    }
    while(refPtr != NULL){
        refPtr = refPtr -> next;
        mainPtr = mainPtr -> next;
    }
    return mainPtr -> data;
    }
}


void Node :: insertNodeAtBeginning(int x){
        Node *temp = createNode();
        temp -> data = x;
        temp -> next = head;
        head = temp;
           
}



void Node :: insertNodeAtEnd(int x){
    Node *newNode = createNode();
    newNode -> data = x;
    Node *temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
    newNode -> next = NULL;

}

void Node :: display(){
    cout << endl;
    Node *temp = head;
    while(temp != NULL){
        cout << temp -> data << " --> ";
        temp = temp -> next;
    }
    cout << "NULL";
    cout << endl;

}
int main(){
    Node o,p;
    int arr[] = {21, 43, 41, 21, 12, 11, 12};
    for(int i = 0; i < 7; i++){
        o.insertNodeAtBeginning(arr[i]);
        
    }
    o.display();
    Node *head = o.returnHead();
    cout << o.getNthFromLast(head, 3);
   

}   
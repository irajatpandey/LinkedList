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
    Node *returnHead();
    void display();
    void setHead(Node *newHead){
        head = newHead;
    }
};    

Node *Node :: returnHead(){
    return head;
}

void Node :: insertNodeAtBeginning(int x){
        Node *temp = createNode();
        temp -> data = x;
        temp -> next = head;
        head = temp;
        
    
}

Node* Node :: merge(Node *head1, Node *head2){
    Node *finalHead = NULL, *finalTail = NULL;
    while(head1 != NULL and head2 != NULL){
    if(head1 -> data > head2 -> data){
        if(finalHead == NULL){
        finalHead = head2;
        finalTail = head2;
        }
        else{
            finalTail -> next = head2;
            finalTail = head2;
        }
        head2 = head2 -> next;
    }
    else
    {   if(finalHead == NULL){
        finalHead = head1;
        finalTail = head1;
        }
        else{
            finalTail -> next = head1;
            finalTail = head1;
        }
        head1 = head1 -> next;
    }
    
}
if(head1 != NULL){
    finalTail -> next = head1;
}
if(head2 != NULL){
    finalTail -> next = head2;
}
return finalHead;
        
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
Node* Node :: reverseList_BruteForce(Node *head){
    if(head == NULL or head -> next == NULL) // base case
        return head;

    Node *smallHead = reverseList_BruteForce(head -> next); // Induction Hypothesis
    Node * tail = smallHead;
    
    while(tail -> next != NULL){
        tail = tail -> next;
    }    
    tail -> next = head;
    head -> next = NULL;
    return smallHead;
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
    o.insertNodeAtBeginning(30);
    o.insertNodeAtBeginning(22);
    o.insertNodeAtBeginning(20);
    o.insertNodeAtBeginning(5);
    o.insertNodeAtBeginning(1);
    
    
    p.insertNodeAtBeginning(11);
    p.insertNodeAtBeginning(6);
    p.insertNodeAtBeginning(3);
    p.insertNodeAtBeginning(2);
   
    Node *head1 = o.returnHead();
    Node *head2 = p.returnHead();
    Node *newHead;
    newHead = o.merge(head1, head2);
    o.setHead(newHead);
    o.display();
}

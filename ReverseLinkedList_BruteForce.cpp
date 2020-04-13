#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *createNode(){
        Node *temp = new Node();
        return temp;
    }

    void insertNodeAtBeginning(int); 
    void insertNodeAtEnd(int);
    Node *reverseList_BruteForce(Node *);
    void display();
};    
Node *head = NULL;

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
    Node o;
    o.insertNodeAtBeginning(10);
    o.insertNodeAtBeginning(20);
    o.insertNodeAtBeginning(30);
    o.insertNodeAtBeginning(40);
    o.insertNodeAtBeginning(50);
    o.display();
    head = o.reverseList_BruteForce(head);
    o.display();

}

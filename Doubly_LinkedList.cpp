#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    Node *head = NULL;
    Node *createNode(int x){
        Node *ptr = new Node();
        ptr -> next = NULL;
        ptr -> prev = NULL;
        ptr -> data = x;
        return ptr;
    }
    Node *returnHead(){
        return head;
    }

    void InsertAtBeginning(int x);
    void InsertAtEnd(int);
    void InsertNodeAtPosition(int, int);
    Node *InsertNodeAtPosition_Recursion(Node *head, int x, int pos);
    void deleteBeginning();
    void deleteEnd();
    void deletePosition(int);
    void display();
};

void Node :: InsertAtBeginning(int x){
    Node *temp = createNode(x);
    if(head != NULL){
        head -> prev = temp;
    }
    temp -> next = head;
    temp -> prev = NULL;
    head = temp;
}

void Node :: InsertAtEnd(int x){
    Node *temp = createNode(x);
    Node *ptr = head;
    while(ptr -> next != NULL){
        ptr = ptr -> next;
    }

    ptr -> next = temp;
    temp -> prev = ptr;
}

void Node :: InsertNodeAtPosition(int x, int pos){
    

     

}

Node *Node :: InsertNodeAtPosition_Recursion(Node *head, int x, int pos){
    /* recursive Approach */

     
        if(pos == 1){
            Node *temp = createNode(x);
            temp -> next = head;
            return temp;
        }
        Node *smallHead = InsertNodeAtPosition_Recursion(head, x,  pos - 1);
            head -> next = smallHead;
            smallHead -> prev = head;
        
        
}

void Node :: deleteBeginning(){
    if(head){
    Node *temp = head;
    head = temp -> next;
    delete temp;
    }

}

void Node :: deleteEnd(){
    Node *temp = head;
    while(temp -> next -> next != NULL){
         temp = temp -> next;
    }
    Node *ptr = temp -> next;
    temp -> next = NULL;
    delete ptr;

}

void Node :: deletePosition(int pos){

}

void Node :: display(){
    Node *temp = head;
    while(temp){
        cout << temp -> data << " ";
         temp = temp -> next;
    }
    cout << endl;
   
}
int main(){
    Node o;
    o.InsertAtBeginning(10);
    o.InsertAtBeginning(20);
    o.InsertAtBeginning(30);
    o.display();

    o.InsertAtEnd(100);
    o.InsertAtEnd(200);
    o.InsertAtEnd(300);
    o.InsertAtEnd(400);
    Node *head = o.returnHead();
   // o.InsertNodeAtPosition_Recursion(head, 123,5);
    o.display();

    o.deleteBeginning();
    o.display();
    o.deleteEnd();
    o.display();


}
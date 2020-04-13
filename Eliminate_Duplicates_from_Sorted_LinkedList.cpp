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
    Node *eliminateDuplicate(Node *head);
    
    void setHead(Node *newHead){
        head = newHead;
    }
    Node *returnHead(){
        return head;
    }
};    

Node *Node :: eliminateDuplicate(Node *head){
    Node *t1 = head;
    Node *t2 = head -> next;
    while(t2 != NULL){
        if(t1 -> data == t2 -> data){
            t1 -> next = t2 -> next;
        }
        else
            t1 = t1 -> next;
        t2 = t2 -> next;
        
        
    }
    return head;
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
    int arr[8] = {5, 5, 4, 3, 3,2 , 2, 1};
    for(int i = 0; i < 8; i++){
        o.insertNodeAtBeginning(arr[i]);
        cout << arr[i];
    }
    o.display();
    Node *head = o.returnHead();
    head = o.eliminateDuplicate(head);
    o.setHead(head);
    o.display();

}   
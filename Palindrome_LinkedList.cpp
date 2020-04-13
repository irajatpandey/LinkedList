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
    bool checkPalindrome();
    Node *middleOftheLinkedList(Node *head);
    Node *reverse(Node*);
    
    void setHead(Node *newHead){
        head = newHead;
    }
    Node *returnHead(){
        return head;
    }
};    

Node *Node :: middleOftheLinkedList(Node *head){
     Node *fastPtr = head;
     Node *slowPtr = head;  

        
        while(fastPtr -> next != NULL and fastPtr != NULL){
            fastPtr = fastPtr -> next -> next;
            slowPtr = slowPtr -> next;
        }
    
    return slowPtr;  
}

Node *Node :: reverse(Node *head){
    if(head == NULL || head -> next == NULL)
        return head;
     Node *smallHead = reverse(head -> next);
     head -> next -> next = head;
     head -> next = NULL;
    return smallHead;    
}


void Node :: insertNodeAtBeginning(int x){
        Node *temp = createNode();
        temp -> data = x;
        temp -> next = head;
        head = temp;
           
}

bool Node :: checkPalindrome(){ 

     Node *middleList , *slowPtr = head, *temp = head, *prev;
     while(temp != NULL and temp -> next != NULL){
         slowPtr = slowPtr -> next;
         prev = slowPtr;
         temp = temp -> next -> next;
        
     }
     if(temp != NULL){
         middleList = slowPtr;
         slowPtr = slowPtr -> next;
     }
     Node *secondHalf = slowPtr;
     prev -> next = NULL;
     Node *smallHead = reverse(secondHalf);
     temp = head;
     while(temp != NULL and smallHead != NULL){
         if(temp -> data == smallHead -> data){
             temp = temp -> next;
             smallHead = smallHead -> next;
         }
         else
            return false;
     }
    return true;
     
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
    int arr[] = {3 ,2 ,1 ,2 ,5 ,4 ,3 ,5 ,1 ,3 ,1 ,5 ,3 ,5 ,5 ,4 ,1 ,3 ,4 ,2 ,4 ,4 ,5 ,4 ,2 ,5 ,5 ,3 ,1 ,2 ,4 ,5 ,3 ,2 ,2};
    for(int i = 0; i < 35; i++){
        o.insertNodeAtBeginning(arr[i]);
    }
    o.display();
    if(o.checkPalindrome()) cout << "YES\n";
    else cout <<"NO\n";

}   
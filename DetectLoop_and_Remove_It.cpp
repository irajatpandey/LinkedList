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
    void removeTheLoop(Node *head);
    void insertNodeAtBeginning(int); 
    void insertNodeAtEnd(int);
    void display();
    void setHead(Node *newHead){
        head = newHead;
    }
    Node *returnHead(){
        return head;
    }
};    




void Node :: insertNodeAtBeginning(int x){
        Node *temp = createNode();
        temp -> data = x;
        temp -> next = head;
        head = temp;
           
}




/* 
1 -> 2 -> 3 -> 4 ->5
        |__________|  
                            */
                            
                        

void Node :: removeTheLoop(Node *head){
     //Your code here
     Node *slow = head;
     Node *fast = head;
     while(fast != NULL and fast -> next != NULL){
         slow = slow -> next;
         fast = fast -> next -> next;
         if(slow == fast)
            break;
     }
     if(slow != fast)
        return;
    slow = head;
    while(slow -> next != fast -> next){
        slow = slow -> next;
        fast = fast -> next;
    }
    fast -> next = NULL;
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
    int arr[] = {5, 4, 3, 2, 1};
    for(int i = 0; i < 5; i++){
        o.insertNodeAtBeginning(arr[i]);
        
    }
    o.display();
    Node *head = o.returnHead();
    
    o.display();
    cout << endl;
    

}   
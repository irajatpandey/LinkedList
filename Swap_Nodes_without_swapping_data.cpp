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
    
    void display();
   
    void swaP(Node *a, Node *b){
        Node *c;
        c = a;
        a = b;
        b = c;
    }
    void swap_Nodes(int x, int y);
    void setHead(Node *newHead){
        head = newHead;
    }
    Node *returnHead(){
        return head;
    }
};    


void Node :: swap_Nodes(int x, int y){
    Node *ptr = head;
    Node *first = NULL;
    Node *prev = NULL;
    Node *second = NULL;
    Node *first_prev = NULL, *second_prev = NULL;
    while(ptr  != NULL){
        if(ptr -> data == x){
            first = ptr;
            
        }
        
        else if(ptr -> data == y){
            second = ptr;
            
        }
       //prev = ptr; 
       ptr = (ptr -> next);     
    }
    if(first && second){
    swap(first, second);
    swap(first -> next, second -> next);
    }

}

void Node :: insertNodeAtBeginning(int x){
        Node *temp = createNode();
        temp -> data = x;
        temp -> next = head;
        head = temp;
           
} 


/* using dummy node*/

/* 1 -> 2 -> 3 -> 4 ->5
        |_____________|
                            */
                        


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
    o.swap_Nodes(2, 4);
    
    o.display();
    cout << endl;
    

}   
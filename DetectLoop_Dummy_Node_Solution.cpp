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
    bool detectLoop(Node *head);
    
    
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


/* using dummy node*/

/* 1 -> 2 -> 3 -> 4 ->5
        |_____________|
                            */
                        
bool Node :: detectLoop(Node *head){
    Node *temp = createNode();
   Node *curr = head;
    while(curr != NULL){
        
       if(curr -> next == NULL)
            return false;
        if(curr -> next == temp)
            return true;
        Node *curr_next = curr -> next;
        curr -> next = temp;   
        curr = curr_next;
    }
    return false;
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
    cout << o.detectLoop(head) << "\n";
    
    o.display();
    cout << endl;
    

}   
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
    void eliminateDuplicate(Node *head);
    
    void setHead(Node *newHead){
        head = newHead;
    }
    Node *returnHead(){
        return head;
    }
};    

void Node :: eliminateDuplicate(Node *head){
      Node *t1 = head;
      

      
      while(t1 != NULL and t1 -> next != NULL){
          Node *t2 = t1;
          while(t2 -> next!= NULL){
              if(t1 -> data == t2 -> next -> data){
                  Node * dup = t2 -> next;
                  t2 -> next = t2 -> next -> next;
                  delete dup;
              }
              else
                t2 = t2 -> next;
          }
          t1 = t1 -> next;
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
    o.eliminateDuplicate(head);
    o.display();

}   
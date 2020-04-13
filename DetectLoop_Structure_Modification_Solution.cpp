#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *head = NULL;
    bool visited;
    Node *createNode(){
        Node *temp = new Node();
        temp -> visited = false;
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

/*bool Node :: detectLoop(Node *head){
    if(head == NULL)
        return false;
    if(head -> next == NULL)
        return false;
    Node *fast = NULL;
    Node *slow = NULL;
    while(fast and slow  and fast -> next){
        
       fast = fast -> next -> next;
       slow = slow -> next; 
       if(fast == slow)
            return true;    
    }
    return false;
    
}*/
bool Node :: detectLoop(Node *head){
    if(head == NULL or head -> next == NULL)
        return false;
    while(head != NULL){
        if(head -> visited == true)
            return false;
        head -> visited = true;    
        head = head -> next;
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
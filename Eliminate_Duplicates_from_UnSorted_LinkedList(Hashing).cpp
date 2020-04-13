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
    void eliminateDuplicate(Node*);
    
    void setHead(Node *newHead){
        head = newHead;
    }
    Node *returnHead(){
        return head;
    }
};    

void Node :: eliminateDuplicate(Node *start){
      set<int> seen; 

	/* Pick elements one by one */
	 Node *curr = start; 
	 Node *prev = NULL; 
	while (curr != NULL) 
	{ 
		// If current value is seen before 
		if (seen.find(curr->data) != seen.end()) 
		{ 
		prev->next = curr->next; 
		delete (curr); 
		} 
		else
		{ 
		seen.insert(curr->data); 
		prev = curr; 
		} 
		curr = prev->next; 
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
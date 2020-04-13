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

    void insertNodeAtBeginning(int);        /* To Insert data at beginning of the Linked List */
    void insertNodeAtEnd(int);
    void insertNodeAtPosition_Iteration(int, int);
    Node* insertNodeAtPosition_Recursion(Node*, int, int);

    void deleteNodeAtBeginning();
    void deleteNodeAtEnd();
    void deleteAtPosition_Iteration(int);
    Node* deleteAtPosition_Recursion(Node*,int);

    int linearSearch_Iteration(Node*, int);        // using iteration 
    bool linearSearch_Recursion(Node*, int);      // will find the element in the linked list if it present using recursion

    void display();
    Node *reverseLinkedList_Recusrion(Node*);   // using recursion we will reverse the LL
    void reverseLinkedList_Iteration();        // using Loop we will reverse the LL

    void calculateLength_Iteration();        // using Iteration we will calculate the Length of the LL
    int calculateLength_Recursion(Node*);   // using Recursion we will calcuate the Length of the LL
    Node* append_LinkedList(Node*, int n);  //  Given a linked list and an integer n, append the last n elements of the LL to front.
    Node* removeDuplicate(Node*);
    Node* middleOftheLinkedList(Node*);
    bool checkPalindrome(Node*);

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

void Node :: insertNodeAtPosition_Iteration(int x, int p){
    Node *temp = head;
    Node *newNode = createNode();
    newNode -> data = x;
    for(int i = 1; i < p - 1; i++)
        temp = temp -> next;
        newNode -> next = temp -> next;
        temp -> next = newNode;

}

Node* Node :: insertNodeAtPosition_Recursion(Node* head, int x, int pos){
    if(pos == 1){
        Node *newNode = createNode();
        newNode -> data = x;
        newNode -> next = head;
        return newNode;
    }
    Node *smallHead = insertNodeAtPosition_Recursion(head -> next, x, pos - 1);
    head -> next = smallHead;
    return head;
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

void Node :: deleteNodeAtBeginning(){
    Node *temp = head;
    head = head -> next;
    free(temp);
}

void Node :: deleteNodeAtEnd(){
    if(head == NULL){
        cout << "List is Empty\n";
    }

    else{

        Node *temp = head;
        while(temp -> next -> next != NULL){
            temp = temp -> next;
        }

        Node *ptr = temp -> next;
        temp -> next = NULL;
        free(ptr);
    }

}

void Node :: deleteAtPosition_Iteration(int p){
    if(head == NULL){
        cout << "List is Empty\n";
    }
    else{
        Node *temp = head;
        for(int i = 1; i < p - 1; i++){
            temp = temp -> next;
        }
        Node *ptr = temp -> next;
        temp -> next = ptr -> next;
        free(ptr);
    }

}

/* Delete Node at ith Position from the linked list using Recusrion */

Node* Node :: deleteAtPosition_Recursion(Node *head, int pos){
    if(head == NULL)
        return head;
    if(pos == 1){
        Node *temp = head;
        head = head -> next;
        delete temp;
        return head;
        
    }    
     Node *smallHead = deleteAtPosition_Recursion(head -> next, pos -1);
     head -> next = smallHead;
}

void Node :: calculateLength_Iteration(){
    int count = 0;
    Node *temp = head;
    while(temp != NULL){
        count++;
        temp = temp -> next;
    }
    cout <<"Length of the Linked List is: "<< count << endl;

}

/* Recursive Function to calculate the Length of the linked list */

int Node :: calculateLength_Recursion(Node *temp){
   if(temp == NULL)  
      return 0;
    else 
        return 1 + calculateLength_Recursion(temp -> next);

}

Node* Node :: reverseLinkedList_Recusrion(Node *head){
    
    if(head == NULL or head -> next == NULL)
        return head;
        Node *curr = reverseLinkedList_Recusrion(head -> next);

        /*  
            Node *prev = head -> next;
            prev -> next = head;
        */
        
        head -> next -> next = head; // This works exactly same as above two lines
        
        head -> next = NULL;
        return curr;
}

void Node :: reverseLinkedList_Iteration(){
    if(head == NULL){
        cout << "List is Empty\n";
    }
    else{
        Node *current, *prev = NULL, *next;
        current = head;
        while (current != NULL)
        {
            next = current -> next;
            current -> next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        
    }

}

bool Node :: linearSearch_Recursion(Node* head, int x){
    if(head == NULL)
        return false;
    if(head -> data == x)
        return true;
    return linearSearch_Recursion(head -> next, x);      

}

int Node :: linearSearch_Iteration(Node* head, int x){
    if(head == NULL){
        cout << "List is empty\n";
    }
    else{
        bool flag = true;
        while(head != NULL){
            if(head -> data == x){
                //cout << "Element is present in the linked list\n";
                return x;
            }
           
            head = head -> next;    
        }
        return -1;

    }
}

/* Given a linked list and an integer n, append the last n elements of the LL to front. 
    Linked List     1 2 3 4 5
    Input n = 3
    Output          3 4 5 1 2

*/
Node* Node :: append_LinkedList(Node *head, int n){
    Node *temp = head, *head2 = NULL;
    Node *ptr = temp;
    int length = calculateLength_Recursion(head);
    
    for(int i = 1; i < length - n ; i++){
        temp = temp -> next;
    }
    /* break the linked list in two part and merge them to get the desired output */
    head2 = temp -> next;
    Node *newHead = head2;
    temp -> next = NULL;
    while (head2 -> next != NULL){
        head2 = head2 -> next;
    }
    head2 -> next = head;
    return newHead;
    

}

Node *Node :: removeDuplicate(Node *head){
    // your code goes here
    if(head == NULL or head -> next == NULL)
        return head;
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

bool Node :: checkPalindrome(Node *head){
    Node *head2 = head;
    if(head == NULL or head -> next == NULL)
        return head;
     Node* newHead = reverseLinkedList_Recusrion(middleOftheLinkedList(head));
    while(newHead != NULL and head2 != NULL){
        if(head2 -> data == newHead -> data){
            newHead = newHead -> next;
            head2 = head2 -> next;

        }
        else
            return false;
    }
        
    return true;

}

Node* Node :: middleOftheLinkedList(Node *head){
    
    Node *slowPtr = head;
    Node *fastPtr = head;
    while(fastPtr -> next != NULL and fastPtr != NULL){
        fastPtr = fastPtr -> next -> next;
        slowPtr = slowPtr -> next;
    }
    return slowPtr;
}


int main(){
    int choice, data;
     Node o;
    while(true){
        cout << "1. Insert Node at Beginning\n";
        cout << "2. Insert Node at End\n";
        cout << "3. Insert Node at Position (Iteratively)\n";
        cout << "4. Insert Node at Position (Recursively)\n";

        cout << "5. Delete Node at Beginning\n";
        cout << "6. Delete Node at End\n";
        cout << "7. Delete Node at Position (Iteratively)\n";
        cout << "8. Delete Node at Position (Recursively)\n";

        cout << "9. Length of the Linked List (Iteration)\n";
        cout << "10. Length of the Linked List (Recusion)\n";

        cout << "11. Reverse the LinkedList using Recursion\n";
        cout << "12. Reverse the LinkedList using Iteration\n";
        cout << "13. Linear Search in Linked List (Iterative)\n";
        cout << "14. Linear Search in Linked List (Recursive)\n";

        cout << "15. Append last N to First\n"; // Given a linked list and an integer n, append the last n elements of the LL to front.
        cout << "16. Remove Duplicate Node from the Linked List\n";
        cout << "17. Check List is Palindrome\n";
        cout << "18. Merge Two Sorted Linked List\n";
        cout << "19. Display\n";




        cin >> choice;
        int pos;
        switch (choice)
        {
        case 1:
            cout << "Enter the element\n";
            cin >> data;
            o.insertNodeAtBeginning(data);
            o.display();
            break;
         case 2:
            cout << "Enter the element\n";
            cin >> data;
            o.insertNodeAtEnd(data);
            o.display();
            break;  

        case 3:
            cout << "Enter the element and position respectively\n";
            cin >> data >> pos;
            o.insertNodeAtPosition_Iteration(data, pos);
            o.display();
         
            break;  

        case 4:
            cout << "Enter the element and position respectively\n";
            cin >> data >> pos;
            o.insertNodeAtPosition_Recursion(head, data, pos);
            o.display();
            break;

        case 5:
            o.deleteNodeAtBeginning(); 
            cout << "Node has been deleted\n";
            o.display();
            break;

        case 6:
            o.deleteNodeAtEnd();
            cout << "Node has been deleted\n";
            o. display();
            break;

        case 7:
            cout << "Enter the position\n";
            cin >> pos;
            o.deleteAtPosition_Iteration(pos);
            cout << "Node has been deleted\n";
            o.display();
            break;

        case 8:
         cout << "Enter the position\n";
            cin >> pos;
            o.deleteAtPosition_Recursion(head, pos);
            cout << "Node has been deleted\n";
            o.display();
            break;

        case 9:
             cout << o.calculateLength_Recursion(head) << endl;
             break;    

        case 10:
            o.calculateLength_Iteration();
            break;     

        case 11:
            head = o.reverseLinkedList_Recusrion(head);
            o.display();
            break;     

        case 12:
            o.reverseLinkedList_Iteration();
            o.display();
            break;



        case 13:
            cout << "Enter the element that need to be searched\n";
            int ele;
            cin >> ele;
            if(o.linearSearch_Iteration(head, ele))
                cout << "Element has been found" << endl;
             else
                cout << "Not found" << endl;       
            break;        

        case 14:
            cout << "Enter the element that need to be searched\n";
            
            cin >> ele;
             if(o.linearSearch_Iteration(head, ele))
                cout << "Element has been found" << endl;
             else
                cout << "Not found" << endl;       
            break;        

        case 15:
            cout << "Enter the value of n\n";
            cin >> pos;
            head = o.append_LinkedList(head, pos);
            o.display();
            break;   

        case 16:
            head = o.removeDuplicate(head);
            o.display();    
            break;

        case 17:
            cout << o.middleOftheLinkedList(head) << endl;
            break;

        case 18:
            cout << o.checkPalindrome(head) << endl;
            break;


        case 19:
            cout << ".....Linked List.....\n";
            o.display();
            break;


        default: cout << "wrong choice\n";
            break;
        }

    }
   
    


}
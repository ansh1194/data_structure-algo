#include <bits/stdc++.h>

//Node class
class Node{
public:
    int val;
    Node* next;
};


// Funtions to push node in front
void pushNode(Node** head, int data);

// Function to print the list
void printList(Node* head);

// Function to remove duplicates
void removeDuplicates(Node* head);


int main(int argc, char* argv[]){

    /* Start with the empty list */
    Node* head = NULL;
     
    /* Let us create a sorted linked list to test the functions
    Created linked list will be 11->11->11->13->13->20 */
    pushNode(&head, 20);
    pushNode(&head, 13);
    pushNode(&head, 13);
    pushNode(&head, 11);
    pushNode(&head, 11);
    pushNode(&head, 11);                                    
 
    std::cout<<"Linked list before duplicate removal " << std::endl;
    printList(head);
    
 
    /* Remove duplicates from linked list */
    removeDuplicates(head);
 
    std::cout<<"\nLinked list after duplicate removal "<< std::endl;    
    printList(head);            
     
    return 0;

}


void pushNode(Node** head, int data){

    Node* newNode = new Node();
    newNode->val = data;
    newNode->next = *head;
    *head = newNode;

}

void removeDuplicates(Node* head){

    Node* current = head;
    Node* deleteNode = NULL;

    while(current->next!=NULL){
        if(current->val == current->next->val){
            deleteNode = current->next;
            current->next = current->next->next;
            free(deleteNode);
        }else{
            current = current->next;
        }
    }

}

void printList(Node* head){
    
    Node* current  = head;
    while(current!=NULL){
        std::cout << current->val << "\n";
        current = current->next;
    }

}



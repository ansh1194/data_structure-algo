
//Node class
#include <bits/stdc++.h>

class Node{
public:
    int val;
    Node* next;
};

// Funtions to push node in front
void pushNode(Node** head, int data);

// Finstion to put data in the end
void addAtEnd(Node** head, int data);

// Function to put data at a given position
void addAtPosition(Node** head, int data, int position);

// Function to print the list
void printList(Node* head);

// Program to insert a node in a singly linked list 

int main(int argc, char* argv[]){

    // Node creation 
    Node* head =  NULL;


    pushNode(&head, 5);
    pushNode(&head,6);
    pushNode(&head,7);
    
    
    // Pushing node at the head
    pushNode(&head,8);
    // Pushing node at the end 
    // addAtEnd(&head,9);
    // Pushing node at a position
    // addAtPosition(&head,6.5,3);

    // Print the end List
    printList(head);

}

void pushNode(Node** head, int data){

    Node* newNode = new(Node);
    newNode->val = data;
    newNode->next = *head;
    *head = newNode;

}


void addAtEnd(Node** head, int data){

}

void addAtPosition(Node** head, int data, int position){

}


void printList(Node* head){

    Node* current  = head;
    while(current!=NULL){
        std::cout << current->val;
        current = current->next;
    }

}
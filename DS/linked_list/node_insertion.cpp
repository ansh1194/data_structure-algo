#include <bits/stdc++.h>

//Node class
class Node{
public:
    int val;
    Node* next;
};

// Funtions to push node in front
void pushNode(Node** head_ref, int data);

// Finstion to put data in the end
void addAtEnd(Node** head_ref , int data);

// Function to put data at a given position
void addAtPosition(Node** head_ref, int data, int position);

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
    addAtEnd(&head,9);
    // Pushing node at a position
    addAtPosition(&head,1,3);

    // Print the end List
    printList(head);

    return 0;

}

void pushNode(Node** head_ref, int data){

    Node* newNode = new(Node);
    newNode->val = data;
    newNode->next = *head_ref;
    *head_ref = newNode;

}


void addAtEnd(Node** head_ref, int data){

    Node* current = *head_ref;
    Node* new_node = new(Node);
    
    new_node->val = data;

    // if the list is empty 
    if (current == NULL){
        current = new_node;
        return;
    }

    // move to the last element of the linked list 
    while(current->next !=NULL){
        current = current->next;
    }

    // add the new node at the end 
    new_node->next = current->next;
    current->next = new_node;

}

void addAtPosition(Node** head_ref, int data, int position){

    Node* current = *head_ref;
    Node* new_node = new(Node);

    new_node->val = data;

    // move to one position before the point of insertion
    while(position!=1){
        current = current->next;
        position--;
    }

    // add the node at the postion
    new_node->next = current->next;
    current->next = new_node;
    

}


void printList(Node* head){

    Node* current  = head;
    while(current!=NULL){
        std::cout << current->val;
        current = current->next;
    }

}
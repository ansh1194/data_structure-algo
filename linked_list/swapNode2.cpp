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

int main(int argc, char* argv[]){

    // Node creation 
    Node* head =  NULL;


    pushNode(&head,1);
    pushNode(&head,11);
    pushNode(&head,2);
    pushNode(&head,8);
    pushNode(&head,9);
    pushNode(&head,5);
    pushNode(&head,7);

    // Print the end List
    printList(head);

    if(swapNode(head,1,7)){
        // Print the end List
        printList(head);
    }else{
        std::cout << "The List does not contain the data " << std:: endl;
    }

}

void pushNode(Node** head, int data){

    Node* newNode = new(Node);
    newNode->val = data;
    newNode->next = *head;
    *head = newNode;

}


void printList(Node* head){

    Node* current  = head;
    while(current!=NULL){
        std::cout << current->val << "\t";
        current = current->next;
    }
    std::cout << std::endl;

}
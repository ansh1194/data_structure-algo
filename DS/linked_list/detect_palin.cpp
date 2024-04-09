// Library Headers
#include <bits/stdc++.h>

//Node class
class Node{
public:
    int val;
    Node* next;
};


// Funtions to push node in front
void pushNode(Node** head_ref, int data);

// Function to find palindrome
bool isPalin(Node* head);

// Function to reverse the second half of the list
void rev(Node* secondHalf);

// Function to compare the two halves
bool compareList(Node* firstHalf, Node* secondHalf);

int main(int argc, char* argv[]){
    
    // Node creation 
    Node* head =  NULL;


    pushNode(&head, 20);
    pushNode(&head, 4);
    pushNode(&head, 4);
    pushNode(&head, 20);

}

void pushNode(Node** head_ref, int data){

    Node* newNode = new(Node);
    newNode->val = data;
    newNode->next = *head_ref;
    *head_ref = newNode;

}

bool isPalin(Node* head){
    
    Node* firstHalf = head;
    Node* secondHalf = head;
    
        
}


void rev(Node* secondHalf){

}

bool compareList(Node* firstHalf, Node* secondHalf){

}

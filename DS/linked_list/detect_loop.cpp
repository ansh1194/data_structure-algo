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

// Function to print the list
void printList(Node* head);

// Function to detect loop 
bool detectLoop(Node* head);

// Function for length of the loop
int loopLength(Node* head);


int main(int argc, char* argv[]){

    // Node creation 
    Node* head =  NULL;


    pushNode(&head, 20);
    pushNode(&head, 4);
    pushNode(&head, 15);
    pushNode(&head, 10);

    /* Create a loop for testing */
    head->next->next->next->next = head;

    if(detectLoop(head)){
        std::cout << "Linked List has Loops" << std::endl;
    }else{
        std::cout << "Linked List has no Loops" << std::endl;
    }

    std::cout << "the length of the loop is :" << loopLength(head) << std::endl;

    return 0;
}


void pushNode(Node** head_ref, int data){

    Node* newNode = new(Node);
    newNode->val = data;
    newNode->next = *head_ref;
    *head_ref = newNode;

}

bool detectLoop(Node* head){

    if(head == NULL){
        return false;
    }

    Node* fast = head;
    Node* slow = head;

    // using a fast and a slow pointer to decide whether the list has loops
    // if slow and fast pointer meet at a node the list has loops 
    while(fast!=NULL && slow!=NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(slow == fast){
            return true;
        }
    }

    return false;

}


int loopLength(Node* head){

    if (detectLoop(head)){
        Node* fast = head;
        Node* slow = head;

        while(slow!=fast){
            fast = fast->next->next;
            slow = slow->next;
        }

        int len = 1;
        fast = fast->next;
        while(fast!=slow){
            fast = fast->next;
            len++;
        }
        return len;
    }

    return 0;

}


void printList(Node* head){

    Node* current  = head;
    while(current!=NULL){
        std::cout << current->val;
        current = current->next;
    }

}
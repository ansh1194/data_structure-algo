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

// Funtion to delete duplicates
bool swapNode(Node* head, int val1, int val2);


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

bool swapNode(Node* head, int val1, int val2){

    Node* swap1 = head;
    Node* swap2 = head;
    Node* prev1 = NULL;
    Node* prev2 = NULL;
    Node* temp = NULL;

    while( swap1!=NULL && swap2!=NULL && (swap1->val != val1 || swap2->val != val2 )){
        if (swap1->val != val1){
            prev1 = swap1;
            swap1 = swap1->next;
        }
        if (swap2->val != val2){
            prev2 = swap2;
            swap2 = swap2->next;
        }
    }

    if (swap1 == NULL || swap2 == NULL){
        return false;
    }else{

        swap1 = prev1->next;
        swap2 = prev2->next;

        prev1->next = swap2;
        prev2->next = swap1;
        temp = swap2->next;
        swap2->next = swap1->next;
        swap1->next = temp;

        return true;
    }
}

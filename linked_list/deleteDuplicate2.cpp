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
void deleteDuplicate(Node* head);


int main(int argc, char* argv[]){

    // Node creation 
    Node* head =  NULL;


    pushNode(&head,12);
    pushNode(&head,11);
    pushNode(&head,12);
    pushNode(&head,8);
    pushNode(&head,9);
    pushNode(&head,12);
    pushNode(&head,11);


    deleteDuplicate(head);
    

    // Print the end List
    printList(head);

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

void deleteDuplicate(Node* head){

    std::unordered_set<int> seen;

    Node* curr = head;
    Node* prev = NULL;

    while(curr!=NULL){

        if(seen.find(curr->val) != seen.end()){
            prev->next = curr->next;
            delete(curr);
        }else{
            seen.insert(curr->val);
            prev = curr;
        }
        curr = prev->next;
    }

}
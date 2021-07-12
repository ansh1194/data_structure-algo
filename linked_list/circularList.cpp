#include <bits/stdc++.h>

// Node Class
class Node{
public:
    int data;
    Node* next;
};

// insert new node in the list
void push(Node** head_ref, int val);

// printing the list 
void printList(Node* head);


int main(int argc, char** argv){

    // Initialize head node
    Node* head = NULL;

    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    push(&head,5);
    push(&head,6);

    std::cout << "List created" << std::endl;
    // print the list
    printList(head);
}


void push(Node** head_ref, int val){

    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = *head_ref;

    Node* temp = *head_ref;

    if(*head_ref!=NULL){
        while(temp->next != *head_ref){
            temp = temp->next;
        }
        temp->next = newNode;
    }else{
        newNode->next =  newNode;
    }

    *head_ref = newNode;

}


void printList(Node* head){

    Node* temp = head;

    if(head!=NULL){
        do{
            std::cout << temp->data << "\t";
            temp = temp->next;
        }while((temp!= head));
    }
    std::cout << std::endl;
}
#include<iostream>
#include<set>

using namespace std;

//creating some nodes in Linked List
void createNewNode(int *numberToAdd, int size);
//to traverse the linked list
void traverse();
//function to get address of any node 
struct node * getNodeAddress(int nodeNumber);
//function to delete the node 
void deleteNode();


struct node{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *current=NULL;

int main(){
    //first i am creating some singly linked list in which some of the data is duplicate
    //Elements will be added in the reverse order
    int duplicateNumber[] = {1 , 2 , 3 , 22 , 45 , 11 , 1 , 2 ,22 , 67 , 45 , 88};
    createNewNode(duplicateNumber , 12);
    //make sure you enter the number between the length of the linked list
    current = getNodeAddress(6);
    deleteNode();
    traverse();
    return 0;
}

void deleteNode(){
    if(current == NULL || current->next == NULL){
        cout<<"\nEither the list is empty or you are trying to delete the last node\n";
        return ; 
    }
        current->data = current->next->data;
        current->next = current->next->next;
}


void createNewNode(int *numberToAdd , int size){
    for(int i=0; i<size ; i++){
        struct node  *ptr = (struct node*)malloc(sizeof(struct node));
        ptr->data=*(numberToAdd+i);
        ptr->next = NULL;
         if(start == NULL){
            start=ptr;
        }else{
            current = start;
            while(current->next != NULL){
                current = current->next;
            }
            current->next = ptr;
        }
    }  
}

struct node* getNodeAddress(int nodeNumber){
    int i =1;
    current  = start;
    cout<<"\n";
    while(current != NULL){
        if(i==nodeNumber){
            return current;
        }
        current=current->next;
        i++;
    }
    return NULL;
}

void traverse(){
    current  = start;
    cout<<"\n";
    while(current != NULL){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<"\n";
}


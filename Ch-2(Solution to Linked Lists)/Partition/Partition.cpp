#include<iostream>
#include<set>

using namespace std;

//creating some nodes in Linked List
void createNewNode(int *numberToAdd, int size);
//to traverse the linked list
void traverse();
//fucntion for partition
void partition(int value);

struct node{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *current=NULL;

int main(){
    //first i am creating some singly linked list in which some of the data is duplicate
    //Elements will be added in the reverse order
    //int duplicateNumber[] = {1 , 2 , 3 , 22 , 45 , 11 , 1 , 2 ,22 , 67 , 45 , 88};
    int duplicateNumber[] = {10  , 9 , 8 , 7 , 6 , 5 , 4 , 3 ,2 ,1};
    createNewNode(duplicateNumber , 10);
    traverse();
    partition(5);
    traverse();
    return 0;
}
//here i am assuming that list is not empty 
void partition(int value){
    struct node *previous = NULL;
    current = start ;
    int flag = 0 ;    
    while(current != NULL){
        if(current->data >= value){
            flag = 1;
        }
        if(flag == 1){
            if(current->data < value && previous != NULL){
                previous->next = current->next;
                current->next = start;
                start = current;
                current = previous;
            }
        }
        previous = current;
        current = current->next;
    }
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


void traverse(){
    current  = start;
    cout<<"\n";
    while(current != NULL){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<"\n";
}

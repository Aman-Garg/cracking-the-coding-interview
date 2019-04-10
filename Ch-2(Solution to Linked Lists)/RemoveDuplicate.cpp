#include<iostream>
#include<set>

using namespace std;

//creating some nodes with some duplicate data
void createNewNode(int *numberToAdd, int size);
//to traverse the linked list
void traverse();
//function to remove Duplicates with complexity O(n)
void removeDuplicates();


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
    removeDuplicates();
    traverse();
    return 0;
}

void removeDuplicates(){
    set<int , greater<int> > nonDuplicateData ;
    current = start;
    //to hold the address of the previous node
    struct node *previous;
    while(current != NULL){
        if(nonDuplicateData.count(current->data) == 1){
            previous->next = current->next;
        }else{
            nonDuplicateData.insert(current->data);
            previous = current ; 
        }
        current = current->next;
    }
}

void createNewNode(int *numberToAdd , int size){
    for(int i=0; i<size ; i++){
        current = (struct node*)malloc(sizeof(struct node));
        current->next = start;
        current->data = *(numberToAdd+i);
        start = current;
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


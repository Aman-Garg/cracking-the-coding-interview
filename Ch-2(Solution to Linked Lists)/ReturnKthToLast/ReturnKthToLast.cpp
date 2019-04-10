#include<iostream>
#include<set>

using namespace std;

//creating some nodes in Linked List
void createNewNode(int *numberToAdd, int size);
//to traverse the linked list
void traverse();
//returning kth to last element
void returnKthToLast();


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
    cout<<start->data;
    returnKthToLast();
    traverse();
    return 0;
}

void  returnKthToLast(){
    int k ;
    cin>>k;
    struct node *addressOfkthNode = NULL;
    current = start;
    addressOfkthNode = start;
    int i= 1;
    while(current != NULL){
        if(i > k){
            addressOfkthNode = addressOfkthNode->next;
        }
        current= current->next;
        i++;
    }
        cout<<addressOfkthNode->data;
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


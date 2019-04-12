#include<iostream>
#include<set>

using namespace std;

//creating some nodes in Linked List
void createNewNode(int *numberToAdd, int size);
//to traverse the linked list
void traverse();
//fucntion for partition
bool checkPalindrome();

struct node{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *current=NULL;

int main(){
    int data[] = {1 , 2 , 3 ,4 ,  3 , 2 ,1};
    createNewNode(data , 7);
    traverse();
    cout<<"\n"<<checkPalindrome()<<"\n";
    return 0;
}


bool checkPalindrome(){
    struct node *first , *second , *temp  , *current;
    first = start;
    current = NULL;
    second = start->next;
    while(second != NULL){
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = first->data;
        temp->next = current;
        current = temp ; 
        if(second->next != NULL){
            second = second->next->next;
            first = first->next;
        }else
            second = NULL;
    }
            first = first->next;
    while(first != NULL && current != NULL){
        if(first->data != current->data){
            return false;
        }
        first = first->next;
        current = current->next;
    }
    if(first != NULL)
        return false;
    return true ;

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

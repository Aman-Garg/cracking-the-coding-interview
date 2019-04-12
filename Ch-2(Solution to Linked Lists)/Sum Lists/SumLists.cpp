#include<iostream>
#include<set>

using namespace std;

//creating some nodes in Linked List
struct node* createNewNode(int *numberToAdd, int size);
//method to add two lists
//assuming that both linked list have same size
void addList(struct node *  , struct node *);
void traverse(struct node*);

struct node{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *current =NULL;

int main(){
    struct node *number1 , *number2;
    int num1[] = {6,1,7};
    int num2[] = {2,9,5};
    number1 = createNewNode(num1 , 3);
    number2 = createNewNode(num2 , 3);
    addList(number1 , number2);
    traverse(start);
    return 0;
}

void addList(struct node *number1, struct node *number2){ 
    start = NULL;
    struct node *previous1 = NULL, *previous2 =NULL; 
    struct node *next1 = NULL, *next2 =NULL; 
    while(number1 != NULL){
        next1 = number1->next;
        next2 = number2->next;
        number1->next = previous1;
        number2->next = previous2;
        previous1 = number1;
        previous2 = number2;
        number1 = next1;
        number2 = next2;
    }
    number1 = previous1;
    number2 = previous2;
    int carry =0 ;
    int result = 0 ;  
    while(number1 != NULL){
        result = (number1->data + number2->data) + carry;
        carry = result/10;
        current = (struct node*)malloc(sizeof(struct node));
        current->data = result%10;
        current->next = start;
        start = current;
        number1= number1->next;
        number2=number2->next;
    }
    if(carry != 0){
        current = (struct node*)malloc(sizeof(struct node));
        current->data = result%10;
        current->next = start;
        start = current;
    }
}


struct node* createNewNode(int *numberToAdd , int size){
    start = NULL;
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
    return start;
}


void traverse(struct node* address){
    current  = address;
    cout<<"\n";
    while(current != NULL){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<"\n";
}

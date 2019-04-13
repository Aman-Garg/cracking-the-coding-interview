#include<iostream>
#include<set>

using namespace std;

//creating some nodes in Linked List
struct node* createNewNode(int *numberToAdd, int size);
void traverse(struct node*);
//function to find the addres of the same node so that i can add it to new list
struct node* findAddress(int n ,struct node *list);
//function to find the length and address of the last node of the list 
struct node* findDetails(struct node*);
//fucntion to find the address of the intersection node
struct node* intersectionNodeAddress(struct node *list1 , int list1Len ,  struct node *list2 , int list2Len);

struct node{
    int data;
    struct node *next;
};


struct node *start = NULL;
struct node *current =NULL;

int main(){
    struct node *list1 , *list2;
    int num1[] = {6 , 1 , 7 , 8 , 45 , 56 , 343};
    int num2[] = {2 , 9 , 5};
    list1 = createNewNode(num1 , 7);
    list2 = createNewNode(num2 , 3);
    //with this i am getting the address of the 6th node of linked list 1
    //and adding this addess to the third node of linked list2
    if(findAddress(3 , list2) != NULL && findAddress(6 , list1) != NULL)
        findAddress(3 , list2)->next = findAddress(6 , list1);
    traverse(list1);
    traverse(list2);
    //till the above line i have just merged the two linkedList only
    struct node *list1Details , *list2Details;
    //both these variable contains the length of list and adrres of the last node
    list1Details = findDetails(list1);
    list2Details = findDetails(list2);
    if(list1Details->next->data != list2Details->next->data){
        //beacuse last node data is not same
        cout<<"\nNo Intersection\n";
    }else{
        cout<<"\n"<<intersectionNodeAddress(list1 ,list1Details->data  ,  list2 , list2Details->data)->data<<"\n";
    }
    return 0;
}


struct node* intersectionNodeAddress(struct node *list1 , int list1Len ,  struct node *list2 , int list2Len){
    if(list1Len >= list2Len ){
        start = list1;
        current = list2;
    }else{
        start = list2;
        current = list1;
    }
    int noOfDiffElement = abs(list1Len-list2Len);
    while(start != NULL){
        if(current == start){
            return start;
        }
        if(noOfDiffElement > 0){
            noOfDiffElement--;
            start = start->next;
        }else{
            current = current->next;
            start = start->next;
        }
    }
    return NULL;
}

struct node* findAddress(int n , struct node *list){
    current = list;
    int i=1;
    while(list != NULL){
        if(i==n){
            return current ;
        }
        i++;
        current= current->next;
    }
    return current;
}

//function to find the length 
struct node* findDetails(struct node* list){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = 0 ; 
    temp->next = NULL;
    while(list != NULL){
        temp->data++;
        temp->next = list;
        list = list->next;
    }
    return temp;
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

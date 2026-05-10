#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int choice=0;
int i= 400;
//tree
struct tree_node {
   char data[10];
   struct tree_node *right;
   struct tree_node *left;
};
struct tree_node* create_node(char value[]) {
    struct tree_node* new_node = (struct tree_node*)malloc(sizeof(struct tree_node));

    strcpy(new_node->data,value);
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}
void displayTree(struct tree_node* root) {

    if (root != NULL) {
        printf("\n%s : %d", root->data,i-=100);
        displayTree(root->left);
        displayTree(root->right);
    }
}


//queue
#define size 5

struct Product {
    char type[20];
    int price;
};
struct Product queue[size];
int front = -1;
int rear = -1;
void enqueue(char itemType[], int itemPrice) {
    if (rear == size - 1) {
        printf("Full\n");
    } else {
        if (front == -1) front = 0;
        rear++;
        strcpy(queue[rear].type, itemType);
        queue[rear].price = itemPrice;
        printf("\n Added: %s\n", itemType);
    }
}
void dequeue() {
    if (front == -1 || front > rear)
        printf("Empty\n");
    else {
        printf("Removed: %s\n", queue[front].type);
        front++;
    }
}

//stack
#define max 5

char stack[max][100];
int top=-1;

void visit (char val[]){
if(top==max-1)
    printf("History is full");
else{
    top++;
    strcpy(stack[top],val);
}
}
void back(){
if (top==-1)
    printf("No history has been found\n");
else
    top--;
}
void view_history(){

if(top==-1){
    printf("No history has been found\n");
}

else{
    printf("Browsing history:\n");
           for(int i=top;i>=0;i--){
              printf("%s\n",stack[i]);
}
}
}

//linked list
struct cart_node {
    char item_name[30];
    int price;
    struct cart_node *next;
};

struct cart_node* add_to_cart(struct cart_node* head, char name[], int p) {
    struct cart_node* newNode = (struct cart_node*)malloc(sizeof(struct cart_node));
    strcpy(newNode->item_name, name);
    newNode->price = p;
    newNode->next = head;
    return newNode;
}

void view_cart(struct cart_node* head) {
    struct cart_node* temp = head;
    if (temp == NULL) {
        printf("\nYour shopping cart is empty.\n");
        return;
    }
    printf("\n Shopping Cart Content: \n");
    while (temp != NULL) {
        printf("Product: %-15s | Price: %d e.g\n", temp->item_name, temp->price);
        temp = temp->next;
    }
}

int main()
{

       struct tree_node* root = create_node("Dress");
    root->left = create_node("Bag");
    root->right = create_node("Shose");

    struct cart_node* my_cart = NULL;

    printf("Hello to shopping system!\n");

    while(choice!=5){
    printf("\n\n please chose number \n 1-show categories \n 2-order \n 3-view history \n 4-chopping cart\n 5-exit \n");
    scanf("%d", &choice);
    switch(choice){
case 1 :
     printf("The categories are:\n ");
    displayTree(root);
    break;
case 2 :
    int order=0;
    while (order != 5){
    printf("enter what you want to buy: !!max5 things!! \n 1-dress \n 2-bag \n 3-chose \n 4-remove \n 5-exit \n");
    scanf("%d", &order);
      switch (order){
  case 1:
     enqueue("Dress", 300);
      visit("dress");
      my_cart = add_to_cart(my_cart, "dress", 300);
    break;
  case 2:
    enqueue("Bag", 200);
     visit("bag");
     my_cart = add_to_cart(my_cart, "bag", 200);
    break;
  case 3:
      enqueue("Shoes", 100);
       visit("shoes");
       my_cart = add_to_cart(my_cart, "shose", 100);
    break;
    case 4:
      dequeue();
        back();
    break;
  case 5:
    printf("exiting..");
    break;
  default:
    printf("valid input");
      }
      }
    break;
case 3 :
   view_history();
    break;
case 4 :
      view_cart(my_cart);
    break;
case 5:
    printf("exiting..");
    break;
  default:
    printf("valid input");
    }
    }
    return 0;
}

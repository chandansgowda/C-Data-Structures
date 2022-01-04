#include <stdio.h>
#include <stdlib.h>

int top = -1;

struct node{
    int info;
    struct node* link;
};

typedef struct node* NODE;


NODE push(NODE stack, int data){
    NODE new = (NODE)malloc(sizeof(struct node));
    new->info=data;
    if (top==-1) {
        new->link = NULL;
        return new;
    }
    new->link = stack;
    printf("Push Successfull\n");
    return new;
}

NODE pop(NODE stack){
    if (top==-1){
        printf("Stack Underflow!\n");
        return NULL;
    }
    NODE ptr = stack->link;
    free(stack);
    top--;
    printf("Pop Successfull\n");
    return ptr;
}

void peek(NODE stack){
    if (top==-1){
        printf("Stack Empty\n");
        return;
    }
    printf("%d",stack->info);
}

void print(NODE stack){
    if (top==-1){
        printf("Stack Empty\n");
        return;
    }
    NODE temp = stack;
    while(temp!=NULL){
        printf("%d ",temp->info);
        temp=temp->link;
    }
}


void main(){
    NODE stack = NULL;
    int data, choice;
    while(1){
        printf("\n1.PUSH\n2.POP\n3.PEEK\n4.PRINT\n99.EXIT\nSelect Option>> ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter Data>> ");
                    scanf("%d",&data);
                    stack = push(stack,data);
                    top++;
                    break;
            case 2: stack = pop(stack);
                    break;
            case 3: peek(stack);
                    break;
            case 4: print(stack);
                    break;
            case 9: exit(0);
        }
    }
}

#include <stdio.h>
#include <stdlib.h>

int top = -1;

void push(int *stack,int data){
    if (top==9){
        printf("Stack Overflow\n");
        return;
    }
    *(stack+(++top))=data;
    printf("Push Successfull\n");
}

void pop(int* stack){
    if (top==-1){
        printf("Stack Underflow!\n");
        return;
    }
    top--;
    printf("Pop Successfull\n");
}

void peek(int* stack){
    if (top==-1){
        printf("Stack Empty\n");
        return;
    }
    printf("%d",stack[top]);
}

void print(int* stack){
    if (top==-1){
        printf("Stack Empty\n");
        return;
    }
    for(int i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }
}


void main(){
    int stack[10];
    int data, choice;
    while(1){
        printf("\n1.PUSH\n2.POP\n3.PEEK\n4.PRINT\n99.EXIT\nSelect Option>> ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter Data>> ");
                    scanf("%d",&data);
                    push(stack,data);
                    break;
            case 2: pop(stack);
                    break;
            case 3: peek(stack);
                    break;
            case 4: print(stack);
                    break;
            case 9: exit(0);
        }
    }
}

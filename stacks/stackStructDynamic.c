#include<stdio.h>
#include<stdlib.h>


struct stack {
    int *data;
    int tos;
};

typedef struct stack * STACK;

void print(STACK x){
    printf("S>> \n");
    for(int i = x->tos; i>=0; i--)
        printf("%d\n", *(x->data+i));
}

STACK push(STACK x, int item){
    x->data = (int*)realloc(x->data,(++x->tos+1)*sizeof(int));
    *(x->data+x->tos) = item;
    return x;
}

STACK peek(STACK x){
    if(x->tos == -1) {
        printf("S has no elements\n");
        return x;
    }

    printf("TOP OF S >> %d\n", *(x->data+x->tos));
    return x;
}

STACK pop(STACK x){
    if(x->tos == -1){
        printf("S EMPTY (UNDERFLOW)\n");
        return x;
    }
    x->data = (int*)realloc(x->data,--x->tos+1*sizeof(int));
    printf("POPPED ELEMENT >> %d\n", *(x->data+x->tos));
    return x;
}

void main(){
    STACK s = (STACK)malloc(sizeof(struct stack));
    s->tos = -1;
    int item, choice;

    for(;;){
        printf("!!!___   S   ___!!!\n1. PUSH \n2. PEEK\n3. POP\n4. PRINT\n");
        printf("Enter choice>> ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("Enter Element for Push operation>> ");
                scanf("%d", &item);
                s = push(s, item);
                print(s);
                break;
            
            case 2:
                s = peek(s);
                break;

            case 3:
                s = pop(s);
                print(s);
                break;

            case 4:
                print(s);
                break;

            default:
                exit(0);
        }
    }
}

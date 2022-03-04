#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int *que;
    int f,r;
};

typedef struct Queue * QUEUE;

void insert(QUEUE q){
    if (q->r==4){
        printf("Queue Overflow\n");
        return;
    }
    printf("Enter data>> ");
    scanf("%d",&q->que[++q->r]);
}

void delete(QUEUE q){
    if (q->f>q->r){
        printf("Queue Empty\n");
        return;
    }
    q->f++;
}

void print(QUEUE q){
    if (q->f>q->r){
        printf("Queue Empty\n");
        return;
    }
    for (int i=q->f;i<=q->r;i++){
        printf("%d",q->que[i]);
    }
}

void main(){
    int choice,n;
    printf("Queue size>> ");
    scanf("%d",&n);
    struct Queue Q;
    QUEUE q = &Q;
    q->que = (int*)malloc(n*sizeof(int));
    q->f = 0;
    q ->r = -1;
    while(1){
        printf("\n1.INSERT\n2.DELETE\n3.PRINT\nEnter your choice>> ");
        scanf("%d",&choice);
        switch(choice){
            case 1: insert(q);break;
            case 2: delete(q);break;
            case 3: print(q);
        }
    }
}

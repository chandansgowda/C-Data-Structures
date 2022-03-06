#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int que[5];
    int f,r;
};

typedef struct Queue * QUEUE;

void insert(QUEUE q){
    if (q->r==4){
        printf("Queue Overflow\n");
        return;
    }
    int item;
    printf("Enter data>> ");
    scanf("%d",&item);
    q->que[++q->r]=item;
}

void delete(QUEUE q){
    if (q->f>q->r){
        printf("Queue Empty\n");
        return;
    }
    if(q->f==q->r){
        q->f = 0;
        q->r = -1;
        return;
    }
    int big = q->que[q->f];
    int i, pos;
    for(i=q->f+1;i<=q->r;i++){
        if (q->que[i]>big){
            big = q->que[i];
            pos = i;
        }
    }
    for (i=pos;i>0;i--){
        q->que[i] = q->que[i-1];
    }
    q->f++;
}

void print(QUEUE q){
    if (q->f>q->r){
        printf("Queue Empty\n");
        return;
    }
    for (int i=q->f;i<=q->r;i++){
        printf("%d ",q->que[i]);
    }
}

void main(){
    int choice;
    struct Queue Q;
    QUEUE q = &Q;
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

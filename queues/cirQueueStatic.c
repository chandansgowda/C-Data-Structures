#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int que[5];
    int f,r;
};

typedef struct Queue * QUEUE;

void insert(QUEUE q){
    if ((q->f==0&&q->r==4)||(q->f==q->r+1)){
        printf("Queue Overflow\n");
        return;
    }
    if (q->f==-1) q->f++;
    q->r = (q->r+1)%5;
    printf("Enter data>> ");
    scanf("%d",&q->que[q->r]);
}

void delete(QUEUE q){
    if (q->r==-1&&q->f==-1){
        printf("Queue Empty\n");
        return;
    }
    if (q->r==q->f){
        q->r=-1;
        q->f=-1;
        return;
    }
    q->f = (q->f+1)%5;
}

void print(QUEUE q){
    if (q->r==-1&&q->f==-1){
        printf("Queue Empty\n");
        return;
    }
    int i;
    for(i = q->f;i!=q->r;i = (i+1)%5){
        printf("%d  ",q->que[i]);
    }
    printf("%d",q->que[i]);
}

void main(){
    int choice;
    struct Queue Q;
    QUEUE q = &Q;
    q->f = -1;
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

#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int que[5];
    int f,r;
};

typedef struct Queue * QUEUE;

void checkInsert(QUEUE q, int data){
    int i, j;
    for (i=q->f;i<=q->r;i++){
        if (data>=q->que[i]){
            for(j=q->r+1;j>i;j--){
                q->que[j] = q->que[j-1];
            }
            q->que[i] = data;
            q->r++;
            return;
        }
    }
    q->que[i] = data;
    q->r++;
}

void insert(QUEUE q){
    if (q->r==4){
        printf("Queue Overflow\n");
        return;
    }
    int item;
    printf("Enter data>> ");
    scanf("%d",&item);
    if (q->f==0&&q->r==-1) q->que[++q->r]=item;
    else checkInsert(q,item);
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

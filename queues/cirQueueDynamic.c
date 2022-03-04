#include <stdio.h>
#include <stdlib.h>

int max;

struct Queue{
    int *que;
    int f,r;
};

typedef struct Queue * QUEUE;

void insert(QUEUE q){
    if ((q->f==0&&q->r==max-1)||(q->f==q->r+1)){
        printf("Queue Overflow\n");
        return;
    }
    q->r = (q->r+1)%max;
    if (q->f==-1) q->f++;
    printf("Enter data>> ");
    scanf("%d",&q->que[q->r]);
}

void delete(QUEUE q){
    if (q->f==-1&&q->r==-1){
        printf("Queue Underflow\n");
        return;
    }
    if (q->f==q->r){
        q->f=q->r=-1;
    }
    else{
        q->f = (q->f+1)%max;
    }
}

void print(QUEUE q){
    if (q->f==-1&&q->r==-1){
        printf("Queue Underflow\n");
        return;
    }
    int i;
    for(i = q->f;i!=q->r;i=(i+1)%max){
        printf("%d ",q->que[i]);
    }
    printf("%d ",q->que[i]);
}

void main(){
    int choice,n;
    printf("Queue size>> ");
    scanf("%d",&n);
    struct Queue Q;
    QUEUE q = &Q;
    max = n;
    q->que = (int*)malloc(n*sizeof(int));
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

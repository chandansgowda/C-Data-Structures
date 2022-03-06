#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int que[5];
    int f,r;
};

typedef struct Queue * QUEUE;

void insertFront(QUEUE q){
    if (q->f==0&&q->r==4){
        printf("Queue Overflow\n");
        return;
    }
    int item;
    printf("Enter Data>> ");
    scanf("%d",&item);
    if (q->f==0&&q->r==-1){
        q->que[++q->r] = item;
        return;
    }
    if (q->f>0){
        q->que[--q->f] = item;
        return;
    }
    int i;
    for(i=q->r+1;i>0;i--){
        q->que[i] = q->que[i-1];
    }
    q->que[0] = item;
    q->r++;
}

void insertRear(QUEUE q){
    if (q->f==0&&q->r==4){
        printf("Queue Overflow\n");
        return;
    }
    int item;
    printf("Enter Data>> ");
    scanf("%d",&item);
    if ((q->f==0&&q->r==-1)||(q->r<4)){
        q->que[++q->r] = item;
        return;
    }
    int i;
    for(i=q->f-1;i<4;i++){
        q->que[i] = q->que[i+1];
    }
    q->que[q->r] = item;
    q->f--;
}

void deleteFront(QUEUE q){
    if (q->f>q->r){
        printf("Queue Empty\n");
        return;
    }
    if (q->f==q->r){
        q->f = 0;
        q->r = -1;
        return;
    }
    q->f++;
}

void deleteRear(QUEUE q){
    if (q->f>q->r){
        printf("Queue Empty\n");
        return;
    }
    if (q->f==q->r){
        q->f = 0;
        q->r = -1;
        return;
    }
    q->r--;
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
        printf("\n1.INSERT FRONT\n2.INSERT REAR\n3.DELETE FRONT\n4.DELETE REAR\n5.PRINT QUEUE\nEnter your choice>> ");
        scanf("%d",&choice);
        switch(choice){
            case 1: insertFront(q);break;
            case 2: insertRear(q);break;
            case 3: deleteFront(q);break;
            case 4: deleteRear(q);break;
            case 5: print(q);
        }
    }
}

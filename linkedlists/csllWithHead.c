#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

typedef struct node* NODE;

NODE createNode(){
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    printf("Enter Data>> ");
    scanf("%d",&temp->data);
    temp->link = temp;
    return temp;
}

void display(NODE head){
    if (head->link==head){
        printf("Empty List\n");
        return;
    }
    NODE temp = head->link;
    for(int i = 0; i<head->data; i++){
        printf("%d ",temp->data);
        temp = temp->link;
    }
}

void insAtFront(NODE head){
    NODE newNode = createNode();
    newNode->link = head->link;
    head->link = newNode;
    head->data++;
    return;
}

void insAtEnd(NODE head){
    NODE temp = head->link;
    for(int i=1; i<head->data;i++){
        temp = temp->link;
    }    
    NODE newNode = createNode();
    newNode->link = temp->link;
    temp->link = newNode;
    head->data++;
    return;
}

void delAtFront(NODE head){
    if (head->link==head){
        printf("List Empty\n");
        return;
    }
    NODE ptr = head->link;
    head->link = ptr->link;
    free(ptr);
    head->data--;
    return;
}

void delAtEnd(NODE head){
    if (head->link==head){
        printf("List Empty\n");
        return;
    }
    NODE temp = head;
    for(int i=1; i<head->data;i++){
        temp = temp->link;
    }
    NODE ptr = temp->link;
    temp->link = ptr->link;
    free(ptr);
    head->data--;
    return;
}

void insAtPos(NODE head,int pos){
    if ((head->link==head)||(pos==1)){
        insAtFront(head);
        return;
    }
    NODE temp = head->link;
    for(int i = 1;  i<pos-1;i++){
        temp = temp->link;
    }
    NODE newNode = createNode();
    newNode->link = temp->link;
    temp->link = newNode;
    head->data++;
    return;
}

void delAtPos(NODE head,int pos){
    if (head->link==head){
        printf("List Empty\n");
        return;
    }
    if(pos==1){
        delAtFront(head);
        return;
    }
    NODE temp = head->link;
    for(int i = 1;  i<pos-1;i++){
        temp = temp->link;
    }
    NODE ptr = temp->link;
    temp->link = ptr->link;
    free(ptr);
    head->data--;
}

void search(NODE head,int key){
    if (head->link==head){
        printf("List Empty\n");
        return;
    }
    NODE temp = head->link;
    for(int i=1; i<=head->data;i++){
        if(temp->data==key){
            printf("Key Found at Position - %d\n",i);
            return;
        }
        temp = temp->link;
    }
    printf("Key NOT Found\n");
    return;
    
}


void main(){
    int choice,pos;
    NODE head = (NODE)malloc(sizeof(struct node));
    head->data = 0; head->link = head;
    while(1){
        printf("\n1.Display\n2.Insert At Front\n3.Insert at End\n4.Delete at Front\n5.Delete at End\n6.Insert At Position\n7.Delete At Position\n8.Search Value");
        scanf("%d",&choice);
        switch(choice){
            case 1: display(head); break;
            case 2: insAtFront(head); break;
            case 3: insAtEnd(head);break;
            case 4: delAtFront(head);break;
            case 5: delAtEnd(head);break;
            case 6:{
                printf("Enter Position>> ");
                scanf("%d",&pos);
                if ((pos<1)||(pos>head->data+1)){
                    printf("Invalid Position\n");
                    break;
                }
                insAtPos(head,pos);
                break;
            }
           case 7:{
                printf("Enter Position>> ");
                scanf("%d",&pos);
                if ((pos<1)||(pos>head->data)){
                    printf("Invalid Position\n");
                    break;
                }
                delAtPos(head,pos);
                break;
           }
           case 8: {
                printf("Enter Key>> ");
                scanf("%d",&pos);
                search(head,pos);
                break;
           }
        }
    }
}



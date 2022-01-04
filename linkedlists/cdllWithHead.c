#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *llink,*rlink;
};

typedef struct node* NODE;

NODE createNode(){
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->rlink = temp->llink = temp;
    printf("Enter Data: ");
    scanf("%d",&temp->data);
    return temp;
}

void display(NODE head){
    if (head->data==0){
        printf("List Empty\n");
        return;
    }
    NODE temp = head->rlink;
    for(int i=0;i<head->data;i++){
        printf("%d ",temp->data);
        temp = temp->rlink;
    }
}

void insAtFront(NODE head){
    NODE new = createNode();
    new->llink = head;
    new->rlink = head->rlink;
    new->rlink->llink = new;
    head->rlink = new;
    head->data++;
    if (new->rlink==head) head->llink=new;
}

void insAtEnd(NODE head){
    if (head->data==0){
        insAtFront(head);
        return;
    }
    NODE new = createNode();
    new->llink = head->llink;
    new->rlink = head;
    head->llink->rlink=new;
    head->llink = new;
    head->data++;
}
void delAtFront(NODE head){
    if (head->data==0){
        printf("List Empty\n");
        return;
    }
    NODE ptr = head->rlink;
    head->rlink = ptr->rlink;
    ptr->rlink->llink = head;
    free(ptr);
    head->data--;
}

void delAtEnd(NODE head){
    if (head->data==0){
        printf("List Empty\n");
        return;
    }
    NODE ptr = head->llink;
    head->llink = ptr->llink;
    ptr->llink->rlink = head;
    free(ptr);
    head->data--;
}

void search(NODE head, int key){
    if (head->data==0){
        printf("List Empty\n");
        return;
    }
    NODE temp=head->rlink;
    for(int i=0;i<head->data;i++){
        if (temp->data==key){
            printf("Key Found\n");
            return;
        }
        temp = temp->rlink;
    }
    printf("Key NOT Found\n");
}

void insAtPos(NODE head,int pos){
    NODE temp = head->rlink;
    for(int i=1;i<pos-1;i++){
        temp = temp->rlink;
    }
    NODE new = createNode();
    new->llink = temp;
    new->rlink=temp->rlink;
    temp->rlink->llink = new;
    temp->rlink = new;
    head->data++;
}

void delAtPos(NODE head, int pos){
    if (head->data==0){
        printf("List Empty\n");
        return;
    }
    NODE temp = head;
    for(int i=0;i<pos-1;i++){
        temp = temp->rlink;
    }
    NODE ptr = temp->rlink;
    ptr->rlink->llink = temp;
    temp->rlink = ptr->rlink;
    free(ptr);
    head->data--;
}

void main(){
    int choice,pos;
    NODE head = (NODE)malloc(sizeof(struct node));
    head->data = 0; head->llink = head->rlink = head;
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

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* rlink, *llink;
};

typedef struct node* NODE;

NODE createNode(){
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->llink = NULL;
    temp->rlink = NULL;
    printf("Enter Data>> ");
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
        printf("%d  ",temp->data);
        temp = temp->rlink;
    }
}

NODE insAtFront(NODE head){
    NODE newNode = createNode();
    newNode->rlink = head->rlink;
    newNode->llink = head;
    head->rlink->llink = newNode;
    head->rlink = newNode;
    head->data++;
    return head;
}

NODE insAtEnd(NODE head){
    NODE newNode = createNode();
    newNode->rlink = head;
    newNode->llink = head->llink;
    head->llink->rlink = newNode;
    head->llink = newNode;
    head->data++;
    return head;
}

NODE insAtPos(NODE head){
    int pos;
    printf("Enter Position to insert>> ");
    scanf("%d",&pos);
    if (pos<1||pos>head->data+1){
        printf("Invalid Position\n");
        return head;
    }
    if (pos==1) return insAtFront(head);
    else if (pos==head->data+1) return insAtEnd(head);
    NODE temp = head->rlink;
    for(int i=0;i<pos-1;i++){
        temp = temp->rlink;
    }
    NODE newNode = createNode();
    newNode->rlink = temp;
    newNode->llink = temp->llink;
    temp->llink->rlink = newNode;
    temp->llink = newNode;
    head->data++;
    return head;
}

void search(NODE head){
    int key;
    if (head->data==0){
        printf("List Empty\n");
        return;
    }
    printf("Enter key>> ");
    scanf("%d",&key);
    NODE temp = head->rlink;
    for(int i=0;i<head->data;i++){
        if (temp->data==key){
            printf("Key FOUND\n");
            return;
        }
        temp = temp->rlink;
    }
    printf("Key Not Found\n");
}

NODE delAtFront(NODE head){
    if (head->data==0){
        printf("List Empty\n");
        return head;
    }
    NODE temp = head->rlink;
    head->rlink = temp->rlink;
    temp->rlink->llink = head;
    free(temp);
    head->data--;
    return head;
}

NODE delAtEnd(NODE head){
    if (head->data==0){
        printf("List Empty\n");
        return head;
    }
    NODE temp = head->llink;
    head->llink = temp->llink;
    temp->llink->rlink = head;
    head->data--;
    return head;
}

NODE delAtPos(NODE head){
    if (head->data==0){
        printf("List Empty\n");
        return head;
    }
    int pos;
    printf("Enter Position to insert>> ");
    scanf("%d",&pos);
    if (pos<1||pos>head->data){
        printf("Invalid Position\n");
        return head;
    }
    NODE temp = head->rlink;
    for(int i=0; i<pos-1;i++){
        temp=temp->rlink;
    }
    temp->rlink->llink = temp->llink;
    temp->llink->rlink = temp->rlink;
    free(temp);
    head->data--;
    return head; 
}

NODE reverse(NODE head){
    if (head->data<2){
        return head;
    }
    NODE t = head->rlink;
    NODE temp, cur=NULL, ptr;
    for(int i=0;i<head->data;i++){
        temp = t;
        t = t->rlink;
        temp->rlink = cur;
        if(cur==NULL){
            ptr = temp;
        }
        cur = temp;
        cur->llink = t;
    }
    head->llink = ptr;
    head->rlink = cur;
    cur->llink = head;
    ptr->rlink = head;
    return head;
}

NODE orderedInput(NODE head){
    int i;
    if (head->data==0) return insAtFront(head);
    NODE newNode = createNode();
    NODE temp = head->rlink;
    for(i=0;i<head->data&&(newNode->data)>(temp->data);i++){
        temp = temp->rlink;
    }
    newNode->rlink = temp;
    newNode->llink = temp->llink;
    temp->llink->rlink = newNode;
    temp->llink = newNode;
    head->data++;
    return head;    
}


void main(){
    int choice;
    NODE head = (NODE)malloc(sizeof(struct node));
    head->llink = head->rlink = head;
    head->data = 0; //to store the number of nodes present
    while(1){
        printf("\n----Circular Doubly Linked List Operations----\n");
        printf("1.Display\n2.Insert at Front\n3.Insert at Position\n4.Insert at End\n5.Search\n6.Delete at Front\n7.Delete at Position\n8.Delete At End\n9.Reverse\n10.Ordered Input\n11.Copylist\n");
        printf("Select Option>> ");
        scanf("%d",&choice);
        switch(choice){
            case 1: display(head); break;
            case 2: head = insAtFront(head); break;
            case 3: head = insAtPos(head); break;
            case 4: head = insAtEnd(head); break;
            case 5: search(head); break;
            case 6: head = delAtFront(head); break;
            case 7: head = delAtPos(head); break;
            case 8: head = delAtEnd(head); break;
            case 9: head = reverse(head);break;
            case 10: head = orderedInput(head);break;
            //case 11: copyAndDisplay(head);break;
            
        }     
    }
}

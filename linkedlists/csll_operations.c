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
    temp->link = temp;
    printf("Enter Data >> ");
    scanf("%d",&temp->data);
    return temp;
}

void display(NODE last){
    if (last==NULL){
        printf("List is Empty :(");
        return;
    }
    if (last->link==last){
        printf("%d ", last->data);
        return;
    }
    NODE temp = last->link;
    while(temp->link!=last){
        printf("%d ", temp->data);
        temp = temp->link;
    }
}

NODE insertAtFront(NODE last){
    if (last==NULL){
        last = createNode();
        return last;
    }
    NODE temp = createNode();
    temp->link = last;
    last->link=temp;
    return temp;
}

NODE insertAtEnd(NODE last){
    if (last==NULL){
        last = createNode();
        return last;
    }
    NODE newNode=createNode(), temp = last->link;
    while(temp->link!=last){
        temp = temp->link;
    }
    temp->link = newNode;
    newNode->link = last;
    return last;
}

void main(){
    int choice,key,pos;
    NODE last;
    
    while(1){
        printf("\n----Singly Linked List Operations----\n");
        printf("1.Display\n2.Insert at Front\n3.Insert at Position\n4.Insert at End\n5.Search\n6.Delete at Front\n7.Delete at Position\n8.Delete At End\n9.Reverse\n10.Ordered Input\n11.Copylist\n");
        printf("Select Option>> ");
        scanf("%d",&choice);
        switch(choice){
            case 1: {
                display(last);
                break;
            }
            case 2: {
                last = insertAtFront(last);
                break;
            }
            /*case 3: {
                printf("Enter Position to insert>> ");
                scanf("%d",&pos);
                last = insertAtPos(last,pos);
                break;
            }*/
            case 4: {
                last = insertAtEnd(last);
                break;
            }
            /*case 5: {
                printf("Enter key to search>> ");
                scanf("%d",&key);
                pos = search(first,key);
                if (pos>=0) printf("Key Found at position - %d\n",pos);
                else printf("Key was not found :(\n");
                break;
            }
            case 6: {
                first = deleteAtFront(first);
                break;
            }
            case 7: {
                printf("Enter Position to Delete>> ");
                scanf("%d",&pos);
                first = deleteAtPos(first,pos);
                break;
            }
            case 8: {
                first = deleteAtEnd(first);
                break;
            }
            case 9: {
                first = reverse(first);
                display(second);
                break;
            }
            case 10: {
                first = orderedInput(first);
                break;
            }
            case 11: {
                NODE second;
                second = copyList(first);
                display(second);
                break;
            }
            default: exit(0);*/
        }
    
    }
    



}











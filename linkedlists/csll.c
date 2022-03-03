#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

typedef struct node* NODE;

NODE createNode(){
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->link = temp;
    printf("Enter Data>> ");
    scanf("%d",&temp->data);
    return temp;
}

void display(NODE last){
    if (last==NULL){
        printf("List Empty\n");
        return;
    }
    NODE temp = last->link;
    do{
        printf("%d  ",temp->data);
        temp = temp->link;
    }
    while(temp!=last->link);
    
    
}

NODE insAtFront(NODE last){
    if (last==NULL){
        return createNode();
    }
    NODE newNode = createNode();
    newNode->link = last->link;
    last->link = newNode;
    return last;
}

NODE insAtEnd(NODE last){
    if (last==NULL){
        return createNode();
    }
    NODE newNode = createNode();
    newNode->link = last->link;
    last->link = newNode;
    return newNode;
}

NODE insAtPos(NODE last){
    int pos,i=-1;
    if (last==NULL){
        return createNode();
    }
    printf("Enter Position to insert>> ");
    scanf("%d",&pos);
    if (pos==1) return insAtFront(last);
    NODE temp = last->link;
    NODE prev = last->link;
    do{
        prev = temp;
        temp=temp->link;
        i++;
    }while(temp!=last->link&&i<pos-1);
    if(temp==last->link && i<pos-1){
        return insAtEnd(last);
    }
    if(temp==last->link && i>=pos-1){
        printf("Position Invalid\n");
        return last;
    }
    NODE newNode = createNode();
    newNode->link = temp;
    prev->link = newNode;
    return last;
}

NODE delAtFront(NODE last){
    if (last == NULL){
        printf("List Empty\n");
        return last;
    }
    if (last->link==last){
        free(last);
        return NULL;
    }
    NODE temp = last->link;
    last->link = temp->link;
    free(temp);
    return last;
}

NODE delAtEnd(NODE last){
    if (last == NULL){
        printf("List Empty\n");
        return last;
    }
    if (last->link==last){
        free(last);
        return NULL;
    }
    NODE temp = last->link;
    NODE prev = last->link;
    do{
        prev = temp;
        temp = temp->link;
    }while(temp!=last);
    prev->link = last->link;
    free(temp);
    return prev;
}

NODE orderedInput(NODE last){
    if (last==NULL) return insAtFront(last);
    NODE newNode = createNode();
    NODE temp = last->link;
    NODE prev = last;
    while(temp!=last&&(newNode->data)>(temp->data)){
        prev = temp;
        temp = temp->link;
    }
    if (temp==last&&(newNode->data)>(temp->data)){
        newNode->link = last->link;
        last->link = newNode;
        return newNode;
    }
    
    newNode->link = temp;
    prev->link = newNode;
    return last;
}

/*NODE reverse(NODE last){
    if (last==NULL){
        printf("List Empty\n");
        return last;
    }
    NODE t = last->link;
    NODE temp, cur=NULL, ptr;
    do{
        temp = t;
        t = t->link;
        temp->link = cur;
        if (cur==NULL){
            ptr = temp;
        }
        cur = temp;
    }while(t!=last->link);
    
    ptr->link = cur;
    return ptr;
}*/


void main(){
    int choice;
    NODE last=NULL;
    while(1){
        printf("\n----Circular Singly Linked List Operations----\n");
        printf("1.Display\n2.Insert at Front\n3.Insert at Position\n4.Insert at End\n5.Search\n6.Delete at Front\n7.Delete at Position\n8.Delete At End\n9.Reverse\n10.Ordered Input\n11.Copylist\n");
        printf("Select Option>> ");
        scanf("%d",&choice);
        switch(choice){
            case 1: display(last); break;
            case 2: last = insAtFront(last); break;
            case 3: last = insAtPos(last); break;
            case 4: last = insAtEnd(last); break;
            case 6: last = delAtFront(last); break;
            //case 7: last = delAtPos(last); break;
            case 8: last = delAtEnd(last); break;
            //case 9: last = reverse(last);break;
            case 10: last = orderedInput(last);break;
            //case 11: copyAndDisplay(last);break;
            
        }     
    }
}

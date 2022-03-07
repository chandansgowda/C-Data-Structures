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

void display(NODE first){
    if (first==NULL){
        printf("List Empty\n");
        return;
    }
    NODE temp = first;
    while(temp!=NULL){
        printf("%d  ",temp->data);
        temp = temp->rlink;
    }
}

NODE insAtFront(NODE first){
    if (first==NULL){
        return createNode();
    }
    NODE newNode = createNode();
    newNode->rlink = first;
    first->llink = newNode;
    return newNode;
}

NODE insAtEnd(NODE first){
    if (first==NULL){
        return createNode();
    }
    NODE newNode = createNode();
    NODE temp = first;
    while(temp->rlink!=NULL){
        temp = temp->rlink;
    }
    newNode->llink = temp;
    temp->rlink = newNode;
    return first;
}

NODE delAtFront(NODE first){
    if (first==NULL){
        printf("List Empty\n");
        return first;
    }
    if (first->rlink == NULL){
        free(first);
        return NULL;
    }
    NODE temp = first->rlink;
    free(first);
    return temp;
}

NODE delAtEnd(NODE first){
    if (first==NULL){
        printf("List Empty\n");
        return first;
    }
    if (first->rlink == NULL){
        free(first);
        return NULL;
    }
    NODE temp = first, prev = first;
    while(temp->rlink!=NULL){
        prev = temp;
        temp = temp->rlink;
    }
    prev->rlink = NULL;
    free(temp);
    return first;
}

NODE insAtPos(NODE first){
    int pos,i=0;
    if (first==NULL&&pos>1){
        printf("List Empty and Position Out of Range (1)\n");
        return first;
    }
    printf("Enter Position to insert>> ");
    scanf("%d",&pos);
    if (pos==1) return insAtFront(first);
    NODE temp = first;
    while(temp!=NULL&&i<pos-1){
        temp = temp->rlink;
        i++;
    }
    if (temp==NULL&&i>=pos-1){
        return insAtEnd(first);
    }
    if (temp==NULL){
        printf("Invalid Position\n");
        return first;
    }
    NODE newNode = createNode();
    newNode->rlink = temp;
    newNode->llink = temp->llink;
    temp->llink->rlink = newNode; 
    temp->llink = newNode;
    return first;
}

NODE delAtPos(NODE first){
    int pos,i=0;
    if (first==NULL){
        printf("List Empty\n");
        return first;
    }
    printf("Enter Position to DELETE>> ");
    scanf("%d",&pos);
    if (pos==1) return delAtFront(first);
    NODE temp = first;
    while(temp!=NULL&&i<pos-1){
        temp=temp->rlink;
        i++;
    }
    if (i>=pos-2) return delAtEnd(first);
    if (temp==NULL){
        printf("Invalid Position\n");
        return first;
    }
    temp->llink->rlink = temp->rlink;
    temp->rlink->llink = temp->llink;
    free(temp);
    return first;
}

int search(NODE first){
    int key,pos=1;
    if (first==NULL){
        printf("List Empty\n");
        return -1;
    }
    printf("Enter key>> ");
    scanf("%d",&key);
    NODE temp = first;
    while(temp!=NULL){
        if (temp->data==key){
            printf("Key Found at Pos - %d\n",pos);
            return pos;
        }
        temp=temp->rlink;
        pos++;
    }
    printf("Key Not Found\n");
    return -1;
}

NODE deleteKey(NODE first){
    if (first==NULL){
        printf("List Empty\n");
        return first;
    }
    int key;
    printf("Key>> ");
    scanf("%d",&key);
    NODE temp = first;
    if (temp->data==key){
        return delAtFront(first);
    }
    while(temp->rlink!=NULL && temp->data!=key){
        temp = temp->rlink;
    }
    if (temp->rlink!=NULL&&temp->data==key){
        temp->llink->rlink = temp->rlink;
        temp->rlink->llink = temp->llink;
        return first;
    }
    if (temp->rlink==NULL&& temp->data==key){
        return delAtEnd(first);
    }
    printf("Key not found\n");
    return first;
}

NODE reverse(NODE first){
    if (first==NULL){
        printf("List Empty\n");
        return first;
    }
    NODE t = first, temp, cur=NULL;
    while(t!=NULL){
        temp = t;
        t = t->rlink;
        temp->rlink = cur;
        cur = temp;
        cur->llink = t;
    }
    return cur;
}

NODE copyList(NODE first, NODE ptr){
    if (first==NULL){
        return first;
    }
    NODE temp = first;
    NODE newNode = (NODE)malloc(sizeof(struct node));
    newNode->data = temp->data;
    newNode->llink = ptr;
    newNode->rlink = copyList(temp->rlink, newNode);
    return newNode;
}

void copyAndDisplay(NODE first){
    NODE second = copyList(first,NULL);
    printf("First List : ");
    display(first);
    printf("Second List : ");
    display(second);
    return;
}

NODE orderedInput(NODE first){
    NODE newNode = createNode();
    if (first==NULL){
        return newNode;
    }
    if (first->data>newNode->data){
        first->llink = newNode;
        newNode->rlink = first;
        return newNode;
    }
    NODE temp = first;
    while(temp->rlink!=NULL&&(newNode->data)>(temp->data)){
        temp = temp->rlink;
    }
    if (temp->rlink==NULL&&(newNode->data)>=(temp->data)){
        temp->rlink = newNode;
        newNode->llink = temp;
        return first;
    }
    newNode->llink = temp->llink;
    newNode->rlink = temp;
    temp->llink->rlink = newNode;
    temp->llink = newNode;
    return first;
    
}

void main(){
    int choice;
    NODE first=NULL;
    while(1){
        printf("\n----Doubly Linked List Operations----\n");
        printf("1.Display\n2.Insert at Front\n3.Insert at Position\n4.Insert at End\n5.Search\n6.Delete at Front\n7.Delete at Position\n8.Delete At End\n9.Delete Key\n10.Reverse\n11.Ordered Input\n12.Copylist\n");
        printf("Select Option>> ");
        scanf("%d",&choice);
        switch(choice){
            case 1: display(first); break;
            case 2: first = insAtFront(first); break;
            case 3: first = insAtPos(first); break;
            case 4: first = insAtEnd(first); break;
            case 5: search(first); break;
            case 6: first = delAtFront(first); break;
            case 7: first = delAtPos(first); break;
            case 8: first = delAtEnd(first); break;
            case 9: first = deleteKey(first); break;
            case 10: first = reverse(first);break;
            case 11: first = orderedInput(first);break;
            case 12: copyAndDisplay(first);break;
            
        }     
    }
}

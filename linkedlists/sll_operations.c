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
    temp->link = NULL;
    printf("Enter Data >> ");
    scanf("%d",&temp->data);
    return temp;
}

void display(NODE first){
    if (first==NULL){
        printf("List is Empty :(");
        return;
    }
    NODE temp = first;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }
}

NODE insertAtFront(NODE first){
    if (first==NULL){
        first = createNode();
        return first;
    }
    NODE temp = createNode();
    temp->link = first;
    return temp;
}

NODE insertAtEnd(NODE first){
    if (first==NULL){
        first = createNode();
        return first;
    }
    NODE newNode, temp = first;
    while(temp->link!=NULL){
        temp = temp->link;
    }
    temp->link = createNode();
    return first;
}

NODE insertAtPos(NODE first, int pos){
    if (first==NULL){
        printf("List Empty! Inserting at first.\n");
        return createNode();
    }
    NODE prev,temp;
    temp = first;
    prev = first;
    for(int i=0;(temp->link!=NULL)&&(i<pos-1);i++){
        prev = temp;
        temp = temp->link;
    }
    if ((temp==NULL)||(pos<1)){
        printf("Invalid Position!\n");
        return first;
    }
    else{
        temp = createNode();
        temp->link = prev->link;
        prev->link = temp;
        return first;
    }
}

int search(NODE first,int key){
    NODE temp;
    temp = first;
    int i=1;
    while(temp->data!=key){
        temp = temp->link;
        i++;
        if(temp==NULL){
            return -1;
        }
    }
    return i;
    
}

NODE deleteAtFront(NODE first){
    if (first==NULL){
        printf("List Empty :(\n");
        return first;
    }
    NODE temp = first;
    first = first->link;
    free(temp);
    return first;
}

NODE deleteAtEnd(NODE first){
    if (first==NULL){
        printf("List Empty :(\n");
        return first;
    }
    NODE temp = first;
    while(temp->link->link!=NULL){
        temp = temp->link;
    }
    free(temp->link);
    temp->link = NULL;
    return first;
}

NODE deleteAtPos(NODE first, int pos){
    if (first==NULL){
        printf("List Empty :(\n");
        return first;
    }
    int i=1;
    NODE temp=first;
    while((temp!=NULL)&&(i<pos-1)){
        temp = temp->link;
        i++;
    }
    if ((temp==NULL)||(pos<1)){
       printf("Invalid Position\n");
       return first; 
    }
    NODE ptr = temp->link;
    temp->link = temp->link->link;
    free(ptr);
    return first;
}

NODE reverse(NODE first){
    if (first==NULL){
        printf("List Empty :(\n");
        return first;
    }
    NODE temp, cur=NULL;
    temp = first;
    while(first!=NULL){
        temp = first;
        first = first->link;
        temp->link = cur;
        cur = temp;
    }
    return cur;
}

// NODE orderedInput(NODE first){
//     if (first==NULL){
//         first = createNode();
//         return first;
//     }
//     NODE newNode = createNode();
//     if ((first->link==NULL)||(first->data>newNode->data)){
//         if (newNode->data<first->data){
//             newNode -> link = first;
//             return newNode;
//         }else{
//             first->link=newNode;
//             return first;
//         }
//     }
//     NODE prev,temp = first;
//     while((temp!=NULL)&&((newNode->data)>(temp->data))){
//             prev = temp;
//             temp = temp->link;
//     }
//     if (temp==NULL){
//         prev->link=newNode;
//         return first;
//     }
//     newNode->link=prev->link;
//     prev->link=newNode;
//     return first;
// }

NODE orderedInput(NODE first){
    NODE newNode = createNode();
    if (first==NULL||first->data>newNode->data){
        newNode->link = first;
        return newNode;
    }
    NODE temp=first, prev=first;
    while(temp!=NULL&&(newNode->data)>(temp->data)){
        prev = temp;
        temp = temp->link;
    }
    prev->link = newNode;
    newNode->link = temp;
    return first;
}

NODE copyList(NODE first){
    if (first==NULL){
        return first;
    }
    NODE temp = first;
    NODE newNode = createNode();
    newNode->data=temp->data;
    newNode->link=copyList(temp->link);
    return newNode;
}


void main(){
    int choice,key,pos;
    NODE first;
    
    while(1){
        printf("\n----Singly Linked List Operations----\n");
        printf("1.Display\n2.Insert at Front\n3.Insert at Position\n4.Insert at End\n5.Search\n6.Delete at Front\n7.Delete at Position\n8.Delete At End\n9.Reverse\n10.Ordered Input\n11.Copylist\n");
        printf("Select Option>> ");
        scanf("%d",&choice);
        switch(choice){
            case 1: {
                display(first);
                break;
            }
            case 2: {
                first = insertAtFront(first);
                break;
            }
            case 3: {
                printf("Enter Position to insert>> ");
                scanf("%d",&pos);
                first = insertAtPos(first,pos);
                break;
            }
            case 4: {
                first = insertAtEnd(first);
                break;
            }
            case 5: {
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
                display(first);
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
            default: exit(0);
        }
    
    }
    



}

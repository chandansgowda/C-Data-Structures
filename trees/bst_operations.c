#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *right, *left;
};

typedef struct node* NODE;

NODE createNode(int data){
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = data;
    temp->right = temp->left = NULL;
    return temp; 
}

NODE insert(NODE root, int data){
   if (root==NULL){
    root = createNode(data);
   }
   else if (data<=root->data){
    root->left = insert(root->left,data);
   }
   else{
    root->right = insert(root->right,data);
   }
   return root;
}

int search(NODE root, int key){
    if (root==NULL) return 0;
    else if (root->data == key) return 1;
    else if (root->data>=key) return search(root->left,key);
    else return search(root->right,key);
}

int min(NODE root){
    if (root==NULL) {
        printf("Tree Empty\n");
        return -1;
    }
    NODE current = root;
    while(current->left!=NULL){
        current = current->left;
    }
    return current->data;
}

int max(NODE root){
    if (root==NULL) {
        printf("Tree Empty\n");
        return -1;
    }
    NODE current = root;
    while(current->right!=NULL){
        current = current->right;
    }
    return current->data;
}

void preorder(NODE root){
    if (root==NULL) return;
    else{
        printf("%d-",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NODE root){
    if (root==NULL) return;
    else{        
        inorder(root->left);
        printf("%d-",root->data);
        inorder(root->right);
    }
}

void postorder(NODE root){
    if (root==NULL) return;
    else{        
        postorder(root->left);
        postorder(root->right);
        printf("%d-",root->data);
    }
}

void main(){
    int choice,data,key;
    NODE root = NULL;
    while(1){
        printf("\n1.INSERT\n2.SEARCH\n3.MIN\n4.MAX\n5.PREORDER\n6.INORDER\n7.POSTORDER\nEnter your choice>>");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter data>> ");
                    scanf("%d",&data);
                    root = insert(root,data);
                    break;
            case 2: printf("Enter key to search>> ");
                    scanf("%d",&key);
                    if (search(root,key)==1) printf("Key Found\n");
                    else printf("Key not found\n");
                    break;
            case 3: printf("MINIMUM -- %d",min(root));break;
            case 4: printf("MAXIMUM -- %d",max(root));break;
            case 5: preorder(root); break;
            case 6: inorder(root); break;
            case 7: postorder(root); break;
        }
    }
}

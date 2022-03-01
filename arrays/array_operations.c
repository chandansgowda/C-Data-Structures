#include <stdio.h>
#include <stdlib.h>

void read(int,int*);
void display(int, int*);
int search(int, int*,int);
int sort(int,int*);
void insert(int*,int*,int,int);
void deleteIndex(int*,int*,int);
void deleteValue(int*,int*,int);

void main(){
    int i,n,choice,arr[25],key,pos;
    
    while(1){
        printf("----Array Operations----\n");
        printf("1.Read\n2.Display\n3.Search\n4.Sort\n5.Insert\n6.Delete by Index\n7.Delete by Value\n8.Exit\n");
        printf("Select Option>> ");
        scanf("%d",&choice);
        switch(choice){
            case 1: {
                printf("Enter size of array>>  ");
                scanf("%d",&n);
                read(n,arr);
                break;
            }
            case 2: {
                display(n,arr);
                break;
            }
            case 3: {
                printf("Enter key to search>> ");
                scanf("%d",&key);
                pos = search(n,arr,key);
                if (pos>=0) printf("Key Found at index - %d\n",pos);
                else printf("Key was not found :(\n");
                break;
            }
            case 4: {
                sort(n,arr);
                display(n,arr);
                break;
            }
            case 5: {
                printf("Enter value to insert>> ");
                scanf("%d",&key);
                printf("Enter index to insert>> ");
                scanf("%d",&pos);
                if ((pos<0)|(pos>n)) {
                    printf("Index out of range :(\n");
                    break;
                }
                insert(&n,arr,pos,key); 
                printf("Insertion Successfull :)\n");
                display(n,arr);
                break;
            
            }
            case 6: {
                printf("Enter index of element to delete>> ");
                scanf("%d",&pos);
                if ((pos<0)|(pos>n-1)) {
                    printf("Index out of range :(\n");
                    break;
                }
                deleteIndex(&n,arr,pos);
                display(n,arr);
                break;
            }
            case 7: {
                printf("Enter value to delete>> ");
                scanf("%d",&key);
                deleteValue(&n,arr,key);
                display(n,arr);
                break;
            }
            default: exit(0);
        }
    
    }
    



}

void read(int n,int *arr){
    printf("Enter Array elements>> ");
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }


}
void display(int n, int *arr){
    printf("Stored array >> [");
    for(int i=0;i<n;i++){
        printf(" %d , ",*(arr+i));
    }
    printf("]\n");

}


int search(int n, int *arr, int key){
    for(int i=0;i<n;i++){
        if (*(arr+i)==key){
            return i;
        }
    }
    return -1;

}

int sort(int n,int *arr){
    int temp,flag=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(*(arr+j)>*(arr+j+1)){
                temp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = temp;
                //arr[j] = arr[j] + arr[j+1] - (arr[j+1]=arr[j]); can also be used for swapping
                flag = 1;
            }
        }
        if (flag==0){
            printf("Array is already Sorted\n");
            return 0;
        }
    }
    printf("Array Sorting Successful :)\n");
}

void insert(int *n,int *arr,int pos,int key){
    for(int i = *n;i>=pos;i--){
        *(arr+i)=*(arr+i-1);
    }
    *(arr+pos) = key;
    (*n)++;

}

void deleteIndex(int *n,int *arr,int pos){
    for(int i=pos;i<*n;i++){
        *(arr+i) = *(arr+i+1);   
    }
    (*n)--;
    printf("Deleted Successfully :)\n");
}

void deleteValue(int *n,int *arr,int key){
    int pos = search(*n,arr,key);
    if (pos>=0) deleteIndex(n,arr,pos);
    else printf("%d does not exist in array :(\n",key);
}

























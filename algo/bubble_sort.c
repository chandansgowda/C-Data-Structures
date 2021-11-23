#include <stdio.h>
#include <stdlib.h>

void main(){
   int n,temp,flag=0;
   printf("Enter size of array>>  ");
   scanf("%d",&n); 
   int *arr = (int *)calloc(n,sizeof(int));
   printf("Enter Array elements>> ");
   for(int i=0;i<n;i++){
       scanf("%d",arr+i);
   }   

   for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(*(arr+j)>*(arr+j+1)){
                temp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = temp;
                flag=1;
            }
        }
        if (flag==0){
            printf("Array is already Sorted\n");
            break;
        }
    }
    
    printf("Sorted array >> [");
    for(int i=0;i<n;i++){
        printf(" %d , ",*(arr+i));
    }
    printf("]\n");
}

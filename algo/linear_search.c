 #include <stdio.h>
#include <stdlib.h>

void main(){
   int n,key; 
   printf("Enter size of array>>  ");
   scanf("%d",&n); 
   int *arr = (int *)calloc(n,sizeof(int));
   printf("Enter Array elements>> ");
   for(int i=0;i<n;i++){
       scanf("%d",arr+i);
   }
   printf("Enter key to search>> ");
   scanf("%d",&key);
   
   for(int i=0;i<n;i++){
       if (*(arr+i)==key){
           printf("Key found at index - %d\n",i);
           exit(0);
       }
   }
   printf("Key not found :(\n");
}

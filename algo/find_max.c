#include <stdio.h>
#include <stdlib.h>

void main(){
   int n,max;
   printf("Enter size of array>>  ");
   scanf("%d",&n); 
   int *arr = (int *)calloc(n,sizeof(int));
   printf("Enter Array elements>> ");
   for(int i=0;i<n;i++){
       scanf("%d",arr+i);
   }
   max = *(arr);
   for(int i=1;i<n;i++){
        if (*(arr+i)>max){
            max = *(arr+i);
        }
   }
   printf("Max : %d\n",max);
   

}

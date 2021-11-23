#include <stdio.h>
#include <stdlib.h>

void main(){
   int n,key,low,high,mid;
   printf("Enter size of array>>  ");
   scanf("%d",&n); 
   int *arr = (int *)calloc(n,sizeof(int));
   printf("Enter Array elements>> ");
   for(int i=0;i<n;i++){
       scanf("%d",arr+i);
   }
   printf("Enter key to search>> ");
   scanf("%d",&key);
   
   low=0;
   high=n-1;
   while(low<=high){
        mid = (low+high)/2;
        if (*(arr+mid)==key) {
            printf("Key found at index - %d\n",mid);
            exit(0);
        }
        else if (*(arr+mid)>key) high = mid-1;
        else low=mid+1;
   }
   printf("Key not found :(\n");
    

}

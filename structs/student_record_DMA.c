#include <stdio.h>
#include <stdlib.h>

typedef struct student {
	char name[10];
	int roll_no;
	int m1,m2,m3;
	float avg_marks;	
} STD;

void read(int,STD *);
void display(int, STD *);
float calcAvg(int,int,int);
void sort(int, STD*);

void main(){
    int n,choice;
    STD *s;
    
    while(1){
        printf("----Student Records----\n");
        printf("1.Read\n2.Display\n3.Sort\n4.Exit\n");
        printf("Select Option>> ");
        scanf("%d",&choice);
        switch(choice){
            case 1: {
                printf("Enter number of students >>  ");
                scanf("%d",&n);
                if ((s = (STD*)calloc(n,sizeof(STD)))==NULL){
                	printf("Memory Error");
                	break;
                }
                read(n,s);
                break;
            }
            case 2: {
                display(n,s);
                break;
            }
            case 3: {
                sort(n,s);
                break;
            }     
            default: exit(0);
        }
    
    }
    
}

void read(int n,STD *s){
    printf("   ----Enter Student Details----\n");
    for(int i=0;i<n;i++){
    	printf("\t----Student[%d]----\n",i+1);
    	printf("Name >> ");
        scanf("%s",((s+i)->name));
        printf("Roll number >> ");
        scanf("%d",&((s+i)->roll_no));
        printf("Test-1 Marks >> ");
        scanf("%d",&((s+i)->m1));
        printf("Test-2 Marks >> ");
        scanf("%d",&((s+i)->m2));
        printf("Test-3 Marks >> ");
        scanf("%d",&((s+i)->m3));
        ((s+i)->avg_marks) = calcAvg(((s+i)->m1),((s+i)->m2),((s+i)->m3));
        
    }


}
void display(int n, STD *s){
	printf("-------------------------------------------------------\n");
    printf("No.\tNAME\tROLL_NO\tTEST-1\tTEST-2\tTEST-3\tAVG_MARKS\n");
    for(int i=0;i<n;i++){
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%.2f\n", i+1,((s+i)->name),((s+i)->roll_no),((s+i)->m1),((s+i)->m2),((s+i)->m3),((s+i)->avg_marks));
    }
	printf("-------------------------------------------------------\n");
}
float calcAvg(int m1,int m2,int m3){
	int temp;
	int arr[3] = {m1,m2,m3};
	for(int i=0;i<2;i++){
		if(arr[i]<arr[i+1]){
			temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1]=temp;
		}
	}
	return ((float)(arr[0]+arr[1])/2);	
}

void sort(int n,STD *s){
    STD temp;
    for(int i=0;i<n;i++){
        for (int j=0;j<n-1-i;j++){
            if (((s+j)->roll_no)>((s+j+1)->roll_no)){
                temp = *(s+j);
                *(s+j) = *(s+j+1);
                *(s+j+1) = temp;
                
            }
        }
    }
}






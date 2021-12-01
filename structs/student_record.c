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
int calcAvg(int,int,int);

void main(){
    int n,choice;
    STD *s, record[30];
    s = record;
    
    while(1){
        printf("----Student Records----\n");
        printf("1.Read\n2.Display\n3.Exit\n");
        printf("Select Option>> ");
        scanf("%d",&choice);
        switch(choice){
            case 1: {
                printf("Enter number of students >>  ");
                scanf("%d",&n);
                read(n,s);
                break;
            }
            case 2: {
                display(n,s);
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
        scanf("%s",&((s+i)->name));
        printf("Roll number >> ");
        scanf("%d",&((s+i)->roll_no));
        printf("Test-1 Marks >> ");
        scanf("%d",&((s+i)->m1));
        printf("Test-2 Marks >> ");
        scanf("%d",&((s+i)->m2));
        printf("Test-3 Marks >> ");
        scanf("%d",&((s+i)->m3));
        ((s+i)->avg_marks) = calcAvg(((s+i)->m1),((s+i)->m1),((s+i)->m1));
       
        
    }


}
void display(int n, STD *s){
    printf("ID\tNAME\tROLL_NO\tTEST-1\tTEST-2\tTEST-3\tAVG_MARKS\n");
    for(int i=0;i<n;i++){
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%.2f\n", i+1,((s+i)->name),((s+i)->roll_no),((s+i)->m1),((s+i)->m2),((s+i)->m3),((s+i)->avg_marks));
    }

}

int calcAvg(int m1,int m2,int m3){
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







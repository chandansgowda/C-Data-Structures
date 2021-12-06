#include <stdio.h>
#include <stdlib.h>

typedef struct time {
    int hh,mm,ss;
} TIME;

void read(TIME*);
void display(TIME*);
void update(TIME*);
void add(TIME*);

void main(){
    int choice;
    TIME time_structure;
    TIME* t = &time_structure;
    
    while(1){
        printf("1.Read\n2.Display\n3.Update\n4.Add\n5.Exit\n");
        printf("Select Option >> ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : {
                read(t);
                break;
            }
            case 2 : {
                display(t);
                break;
            }
            case 3: {
                update(t);
                break;
            }
            case 4: {
                add(t);
                break;
            }
            default: {
                exit(0);
                break;
            }
        }
    }
}

void read(TIME* t){
    printf("Enter Time (HH:MM:SS) >>  ");
    scanf("%d:%d:%d",&t->hh,&t->mm,&t->ss);  
}

void display(TIME* t){
    printf("Time >> %.2d:%.2d:%.2d\n",t->hh,t->mm,t->ss);
}

void update(TIME* t){
    t->ss++;
    if(t->ss>=60){
        t->ss-=60;
        t->mm++;
    }
    if (t->mm>=60){
        t->mm-=60;
        t->hh++;
    }
    if (t->hh>=24){
        t->hh-=24;
    }
    printf("Time was updated Successfully\n");
}

void add(TIME* t){
    TIME temp;
    printf("Enter Time (HH:MM:SS) to add >>  ");
    scanf("%d:%d:%d",&temp.hh,&temp.mm,&temp.ss);  
    t->ss += temp.ss;
    if(t->ss>=60){
        t->ss-=60;
        t->mm++;
    }
    t->mm += temp.mm; 
    if (t->mm>=60){
        t->mm-=60;
        t->hh++;
    }
    t->hh += temp.hh;  
    if (t->hh>=24){
        t->hh-=24;
    } 
    printf("Time addition successful\n");
}

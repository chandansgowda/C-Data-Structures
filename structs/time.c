#include <stdio.h>
#include <stdlib.h>

struct Time {
    int h,m,s;
};

typedef struct Time* TIME;

void read(TIME t){
    printf("Enter time (HH:MM:SS) >> ");
    scanf("%d:%d:%d",&t->h,&t->m,&t->s);
}

void display(struct Time t){
    printf("%.2d:%.2d:%.2d",t.h,t.m,t.s);
}

void update(TIME t){
    t->s++;
    if(t->s>=60){
        t->m++;
        t->s=0;
        if(t->m>=60){
        t->h++;
        t->m=0;
            if(t->h>=24){
            t->h=0;
            }
        }
    }
}

void add(){
    int temp;
    struct Time t1,t2;
    TIME tp1, tp2;
    tp1 = &t1;
    tp2 = &t2;
    printf("\nTime 1\n");
    read(tp1);
    printf("\nTime 2\n");
    read(tp2);
    t1.s += t2.s;
    t1.m += t2.m;
    t1.h += t2.h;
    if (t1.s>59){
        temp = t1.s/60;
        t1.s %= 60;
        t1.m += temp;
        if (t1.m>59){
            temp = t1.m/60;
            t1.m %= 60;
            t1.h += temp;
            if (t1.h>23){
                t1.h %= 24;
            }
        }
    }
    display(t1);
    
}


void main(){
    struct Time time;
    time.h = time.s = time.m = 0;
    TIME t = &time;
    
    int choice;
    while(1){
        printf("\n1.Read\n2.Display\n3.Update\n4.Add Two Times\nEnter your choice>> ");
        scanf("%d",&choice);
        switch(choice){
            case 1: read(t); break;
            case 2: display(time); break;
            case 3: update(t); break;
            case 4: add();break;
        }
    }
}

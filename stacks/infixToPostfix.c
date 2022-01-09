#include <stdio.h>
#include <ctype.h>

char stack[20];
int top = -1;

void push(char x){
    stack[++top] = x;
}

int pop(){
    return stack[top--];
}

int priority(char x){
    if (x == '(') return 0;
    else if (x=='+'||x=='-') return 1;
    else if (x=='*'||x=='/') return 2;
}

int main()
{
   
    char exp[20];
    char *e, x;
    printf("Enter expression>> ");
    scanf("%s",exp);
    e = exp;
    while(*e!='\0'){
        if(isalnum(*e)) printf("%c",*e);
        else if (*e=='(') push(*e);
        else if (*e==')'){
            while((x = pop())!='(') printf("%c",x);
        }
        else{
            while(priority(stack[top])>=priority(*e)) printf("%c",pop());
            push(*e);
        }
        e++;
    }
    while(top!=-1){
        printf("%c",pop());
    }
    
    return 0;
}

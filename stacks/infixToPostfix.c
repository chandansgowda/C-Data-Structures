#include <stdio.h>
#include <ctype.h>

char stack[20];
int top = -1;

char result[20];
int topr = -1;

void push(char x){
    stack[++top] = x;
}

int pop(){
    return stack[top--];
}

void pushres(char x){
    result[++topr] = x;
}

int priority(char x){
    if (x=='(') return 0;
    else if (x=='+' || x=='-') return 1;
    else if (x=='/' || x=='*') return 2;
    else if (x=='^' || x=='$') return 3;
}

void main(){
    char exp[20], *e, x;
    printf("Enter infix expression>> ");
    scanf("%s",exp);
    e = exp;
    while(*e!='\0'){
        if (isalnum(*e)) pushres(*e);
        else if (*e=='(') push(*e);
        else if (*e==')'){
            while((x=pop())!='(') pushres(x);
        }
        else{
            while (priority(stack[top])>=priority(*e)) pushres(pop());
            push(*e);
        }        
        e++;
    }
    while(top>=0){
        pushres(pop());
    }
    printf("Postfix expression>> ");
    for(int i=0; i<=topr; i++){
        printf("%c", result[i]);
    }
    printf("\n");
}

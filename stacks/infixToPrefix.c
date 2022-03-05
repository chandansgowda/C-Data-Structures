#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 25

// Test Case - (a-b/c)*(a/k-l)

char stack[MAX];
int tos = -1;

char res[MAX];
int rtos = -1;

void push(int x){
    stack[++tos] = x;
}

char pop(){
    return stack[tos--];
}

void pushres(char x){
    res[++rtos] = x;
}


int priority(char x){
    if (x==')' || x=='#') return 0;
    else if (x=='+' || x=='-') return 1;
    else if (x=='/' || x=='*') return 2;
}


void main(){
    char exp[MAX], *e, x; 
    printf("Enter infix epression>> ");
    scanf("%s",exp);
    int len = strlen(exp);
    e = &exp[len-1];
    while(len!=-1){
        if (isalnum(*e)) pushres(*e);
        else if (*e==')') push(*e);
        else if (*e=='('){
            while((x=pop())!=')') pushres(x);
        }
        else{
            while(priority(stack[tos])>priority(*e)) pushres(pop());
            push(*e);
        }
        e--;len--;
    }
    printf("Required prefix expression>> ");
    for(int i=rtos; i!=-1; i--){
        printf("%c",res[i]);
    }
    
}

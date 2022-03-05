#include <stdio.h>
#include <ctype.h>
#include <string.h>
int stack[10];
int tos =-1;

void push(char x){
    stack[++tos] = x;
}

int pop(){
    return stack[tos--];
}

void main(){
    char exp[10];char *e;
    int num1, num2, num3, len;
    printf("Enter Prefix expression>> ");
    scanf("%s",exp);
    len = strlen(exp);
    e = &exp[len-1];
    while(len!=-1){
        if (isdigit(*e)) push(*e-48);
        else{
            num1 = pop();
            num2 = pop();
            switch(*e){
                case '+': num3 = num1 + num2; break;
                case '-': num3 = num1 - num2; break;
                case '*': num3 = num1 * num2; break;
                case '/': num3 = num1 / num2; break;
                case '^': num3 = num1 ^ num2; break;
            }
            push(num3);
        }
        e--;len--;
    }
    printf("Value of the Expression >> %d\n",pop());
}

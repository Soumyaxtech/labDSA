#include<iostream>

using namespace std;
char stack[20];
int top = -1;

void push(char val) {
    stack[++top] = val;
}

char pop() {
    if (top == -1) {
        return -1;
    } else {
        return stack[top--];
    }
}
int main() {
    char exp[20];
    char *c, val;
    cout << "Enter the expression: ";
    cin >> exp;
    c = exp;
    while(*c!='\0'){
        if(isalnum(*c)){
            push(*c);
        }
        else{
            char x2=pop();
            char x1=pop();
            switch(*c){
                case '+':
                    push('(');
                    push(x1);
                    push('+');
                    push(x2);
                    push(')');
                    break;
                case '-':
                    push('(');
                    push(x1);
                    push('-');
                    push(x2);
                    push(')');
                    break;
                case '*':
                    push('(');
                    push(x1);
                    push('*');
                    push(x2);
                    push(')');
                    break;
                case '/':
                    push('(');
                    push(x1);
                    push('/');
                    push(x2);
                    push(')');
                    break;
            }
        }
        c++;
    }
    int i=0;
    while(top!=-1){
        cout<<pop();
    }
}
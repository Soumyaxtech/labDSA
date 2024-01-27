#include<iostream>

using namespace std;
int stack[20];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
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
    while (*c != '\0') {
        if (isalnum(*c)) {
            push(*c - '0');
        } 
        else{
            int x2=pop();
            int x1=pop();
            switch(*c){
                case '+':
                    push(x1+x2);
                    break;
                case '-':
                    push(x1-x2);
                    break;
                case '*':
                    push(x1*x2);
                    break;
                case '/':
                    push(x1/x2);
                    break;
            }
        }
        c++;
    }
    if (top != -1) {
        cout << "Result: " << pop();
            } 
    else {
        cout << "Error: Invalid expression" << endl;
        }
}

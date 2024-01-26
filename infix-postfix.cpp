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

int priority(char val) {
    if (val == '(') {
        return 0;
    }
    else if (val == '+' || val == '-') {
        return 1;
    }
    else if (val == '*' || val == '/') {
        return 2;
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
            cout << *c;
        } else if (*c == '(') {
            push(*c);
        } else if (*c == ')') {
            while ((val = pop()) != '(') {
                cout << val;
            }
        } else {
            while ( priority(stack[top]) >= priority(*c)) {
                cout << pop();
            }
            push(*c);
        }
        c++;
    }
    while (top != -1) {
        cout << pop();
    }
    return 0;
}



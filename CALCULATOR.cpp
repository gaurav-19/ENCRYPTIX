#include<iostream>
using namespace std;

int main(){
    int n1,n2;
    cout<<"Enter the first number: ";
    cin>>n1;
    cout<<"Enter the second number: ";
    cin>>n2;
    char op;
    cout<<"Enter the operator (+, -, *, /): ";
    cin>>op;
    switch(op)
    {
        case '+':
            cout<<"Sum: "<<n1+n2;
            break;
        case '-':
            cout<<"Subtraction: "<<n1-n2;
            break;
        case '*':
            cout<<"Multiplication: "<<n1*n2;
            break;
        case '/':
            if(n2!= 0)
                cout<<"Division: "<<n1/n2;
            else
                cout<<"Error: Division by zero is not allowed.";
            break;
        default:
            cout<<"Error: Invalid operator.";
    }
    return 0;
}
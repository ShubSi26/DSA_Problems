#include<iostream>
using namespace std;
void push(int stack[],int &top,int size){
    if(top == size-1){
        cout << "overflow" << endl;
        return;
    }
    int v;
    top++;
    cout << "Enter the value: ";
    cin >> v;
    stack[top] = v;
}
void pop(int stack[],int &top){ 
    if(top == -1){
        cout << "Underflow" << endl;
        return;
    }
    top--;
}
void peek(int stack[],int top){
    if(top == -1){
        cout << "Empty Stack" << endl;
        return;
    }
    cout << stack[top] << endl;
}
void disp(int stack[],int top){
    for(int i=top;i>=0;i--){
        cout << stack[i] << " ";
    }
    cout << endl;
}
int main(){
    int n,top = -1 , choice=1;
    cout << "Enter the size of stack: ";
    cin >> n;
    int stack[n];
    do{
        cout << "1. push" << endl;
        cout << "2. pop" << endl;
        cout << "3. peek" << endl;
        cout << "4. display" << endl;
        cout << "5. exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
            case 1: push(stack,top,n); break;
            case 2: pop(stack,top); break;
            case 3: peek(stack,top); break;
            case 4: disp(stack,top);
        }
    }while(choice != 5);
}
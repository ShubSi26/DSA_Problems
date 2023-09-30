#include<iostream>
using namespace std;
struct node{
    int n;
    node* next;
};
void push(node *&top){
    cout << "ENter the value: ";
    node *t = new node();
    cin >> t->n;
    t->next = top;
    top=t;
}
void pop(node*&top){
    if(top ==NULL){
        cout << "Underflow" << endl;
        return;
    }
    node *tmp = top;
    top=top->next;
    delete(tmp);
}
void peek(node *top){
    cout << top->n << endl;
}
void disp(node *top){
    while(top != NULL){
        cout << top->n << " ";
        top=top->next;
    }
    cout << endl;

}
void mx(node *top){
    int m = top->n;
    while(top != NULL){
        if(top->n > m) m = top->n;
        top=top->next;
    }
    cout << m << endl;
}
void mi(node *top){
    int m = top->n;
    while(top != NULL){
        if(top->n < m) m = top->n;
        top=top->next;
    }
    cout << m << endl;
}
void rev(node *top){
    if(top == NULL) return;
    rev(top->next);
    cout << top->n << " ";
}
int main(){
    node *top = NULL;
    int choice;
    do{
        cout << "1. push" << endl;
        cout << "2. pop" << endl;
        cout << "3. peek" << endl;
        cout << "4. display" << endl;
        cout << "5. Min" << endl;
        cout << "6. Max" << endl;
        cout << "7. Show reverse" << endl;
        cout << "8. exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
            case 1: push(top); break;
            case 2: pop(top); break;
            case 3: peek(top); break;
            case 4: disp(top); break;
            case 5: mi(top); break;
            case 6: mx(top); break;
            case 7: rev(top); cout << endl; break; 
        }
    }while(choice != 8);

}
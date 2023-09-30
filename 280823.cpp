#include<iostream>
using namespace std;

struct node{
    int n;
    struct node* next;
};
struct node* head = NULL;
struct node* tail = NULL;
int main(){
    int n=1;
    while(n){
        cout << "Enter the choice(0,1): ";
        cin >> n;
        if(n==0) break;
        cout << "Enter the data: ";
        int d;
        cin >> d;
        struct node* t = new node();
        t->n =d;
        if(head == NULL){
            head = t;
            tail = t;
        }else{
            tail->next = t;
            tail = t;
        }

    }
    struct node* p=head;
    while(p != NULL){
        cout << p->n << " ";
        p = p->next;
    }
}
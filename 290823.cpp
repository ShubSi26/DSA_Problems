#include<iostream>
using namespace std;

struct node{
    int n;
    struct node* next;
};
void update(node *&head, int p,int d){
    if(p==1){
        struct node* t = new node();
        t->n=d;
        t->next = head;
        head = t;
    }else{
        int i=2;
        node *t = head;
        while(i<p){
            if(t->next != NULL) {
                t=t->next;
                i++;
                }
        }
        struct node* new1 = new node();
        new1->n=d;
        new1->next = t->next;
        t->next = new1;
    }
}
void display(node *h){
    while(h != NULL){
        cout << h->n << " ";
        h = h->next;
    }
    cout << endl;
}
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
    display(head);
    cout << "Enter the position : ";
    int m;
    cin >> m;
    cout << "enter the data: ";
    int d;
    cin >> d;
    update(head,m,d);
    display(head);
}
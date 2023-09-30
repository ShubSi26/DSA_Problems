#include<iostream>
using namespace std;
struct node{
    int d;
    node *next;
    node *pre;
};
void d(node *h){
    while(h != NULL){
        cout << h->d << " ";
        h=h->next;
    }
    cout << endl;
}
void u(node *&h,int m,int p){
    node *t = new node();
    t->d = m;
    if(p == 1){
        h->pre = t;
        t->next = h;
        h = t;
    }else{
        node *a = h;
        for(int i=1;i<p-1;i++){
            a=a->next;
        }
        if(a->next == NULL){
            t->pre = a;
            a->next = t;
        }else{
            a->next->pre = t;
            t->pre = a;
            t->next = a->next;
            a->next = t;
        }
    }
}
int main(){
    node *head = NULL;
    node *tail = NULL;
    int n=1;
    while(n){
        cout << "Enter the choice(0,1): ";
        cin >> n;
        if(n==0) break;
        cout << "Enter the data: ";
        node *t = new node();
        cin >> t->d;
        if(head == NULL){
            head = t;
            tail = t;
        }else{
            tail->next = t;
            t->pre = tail;
            tail = t;
        }
    }
    d(head);
    cout << "Enter the position: ";
    int m; cin >> m;
    cout << "Enter the value: ";
    int p; cin >> p;
    u(head,p,m);
    d(head);
}
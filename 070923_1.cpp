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
void del(node *&head,int p){
    if(p==1){
        head = head->next;
        delete(head->pre);
        head->pre = NULL;
    }else{
        node *a = head;
        for(int i=1;i<p-1;i++){
            a=a->next;
        }
        if(a->next->next == NULL){
            a->next = NULL;
            a->pre = NULL;
        }else{
            a->next->next->pre = a;
            a->next = a->next->next;
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
    int p; cin >> p ;
    del(head,p);
    d(head);
}
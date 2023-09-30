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
void rev(node *&head){
    node *h = head;
    node *nxt = NULL;
    node *pre = NULL;
    while(h != NULL){
        pre = nxt;
        nxt = h->next;
        node *tmp = h->next;
        h->next = h->pre;
        h->pre = tmp;
        h=nxt;
    }
    head = pre;
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
    rev(head);
    d(head);
}
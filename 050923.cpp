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
    cout << "Enter the element to enter: ";
    node *t = new node();
    cin >> t->d;
    t->next = head;
    head->pre = t;
    head = t;
    d(head);
}
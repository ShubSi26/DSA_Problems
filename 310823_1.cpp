#include<iostream>
using namespace std;

struct node{
    int n;
    struct node* next;
};
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
    head = new node();
    head->n = 0;
    tail = head;
    int n=1;
    while(n){
        cout << "Enter the choice(0,1): ";
        cin >> n;
        if(n==0) break;
        cout << "Enter the data: ";
        struct node* t = new node();
        cin >> t->n;
        tail->next = t;
        tail = t;
        head->n+=1;
    }
    display(head);
}
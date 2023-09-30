#include<iostream>
using namespace std;

struct node{
    int n;
    struct node* next;
};
void display(node *head){
    node *h=head->next;
    cout << "No of elements: "<< head->n << endl;
    while(h != head){
        cout << h->n << " ";
        h = h->next;
    }
    cout << endl;
}
struct node* head = NULL;
struct node* tail = NULL;
int main(){
    node *headr = new node();
    headr->n = 0;
    head = headr;
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
        headr->n+=1;
    }
    tail->next = headr;
    display(head);
}
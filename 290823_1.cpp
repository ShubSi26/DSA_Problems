#include<iostream>
using namespace std;

struct node{
    int n;
    struct node* next;
};
void deletell(node *&head, int p){
    if(p==1){
        head=head->next;
    }else{
        int i=1;
        node *t = head;
        while(i<p-1){
            if(t->next != NULL) {
                t=t->next;
                i++;
                }
        }
        t->next = t->next->next;
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
    cout << "Enter the position to delete: ";
    int m;
    cin >> m;
    deletell(head,m);
    display(head);
}
#include<iostream>
using namespace std;

struct node{
    int n;
    struct node* next;
};
int search(node *head, int p){
    int indx = 0;
    while(head != NULL){
        indx++;
        if(head->n == p) return indx;
        head = head->next;
    }
    return -1;
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
    int m;
    cout << "Enter the value to search: ";
    cin >> m;
    int pos = search(head,m);
    if(pos ==-1){
        cout << "Value Not Found";
    }else{
        cout << "Value found at position: "<< pos;
    }
}
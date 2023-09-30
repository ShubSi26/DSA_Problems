#include<iostream>
using namespace std;

struct node{
    int n;
    struct node* next;
};
int main(){
    int n;
    cout << "enter the number of elements: ";
    cin >> n;
    struct node* head = NULL;
    struct node* tail = NULL;
    for(int i=0;i<n;i++){
        int m;
        cin >> m;
        struct node* t = new node();
        t->n =m;
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
    return 0;
}
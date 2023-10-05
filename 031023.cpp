#include<iostream>
using namespace std;
struct node{
    int n;
    int p;
    node* next;
}*head,*rear;
void enq(){
    node *t = new node();
    cout << "Enter the value: " ;
    cin >> t->n ;
    cout << "Enter the priority: ";
    cin >> t->p;
    if(rear == NULL){
        head =t;
        rear = t;
    }else{
        if(t->p > head->p){
            t->next = head;
            head = t;
        }else{
            node *tmp = head;
            while(tmp->next != NULL && t->p < tmp->next->p){
                tmp=tmp->next;
            }
            if(tmp->next == NULL){
                tmp->next = t;
            }else{
                t->next = tmp->next;
                tmp->next = t;
            }
        }
    }
}
void deq(){
    if(head == NULL) {
        cout << "Empty queue" << endl;
        return;
    }else{
        head = head->next;
        if(head == NULL){
            rear = NULL;
        }
    }
}
void dsp(){
    if(head == NULL) {
        cout << "Empty queue" << endl;
        return;
    }else{
        node*tmp = head;
        while(tmp != NULL){
            cout << tmp->n << " ";
            tmp=tmp->next;
        }
        cout << endl;
    }
}
void pek(){
    if(head == NULL) {
        cout << "Empty queue" << endl;
        return;
    }else{
        cout << head->n <<endl;
    }
}
int main(){
    int c;
    while(1){
        cout << "1 Enqueue" << endl;
        cout << "2 dequeue" << endl;
        cout << "3 peek" << endl;
        cout << "4 display" << endl;
        cout << "5 exit" << endl;
        cout << "Enter your choice: ";
        cin >> c;
        if(c==1) enq();
        else if(c==2) deq();
        else if(c==3) pek();
        else if(c==4) dsp();
        else if(c==5) break;
    }
}
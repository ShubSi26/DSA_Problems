#include<iostream>
using namespace std;
struct node{
    int n;
    node *next;
}*front,*rear;
void enq(){
    node *t = new node();
    cout << "Enter he value: " ;
    cin >> t->n;
    if(rear == NULL){
        front = t;
        rear  =t;
    }else{
        rear->next = t;
        rear = t;
    }
}
void deq(){
    if(front ==NULL){
        cout << "Empty Queue" << endl;
        return;
    }
    node * t = front;
    front = front->next;
    delete(t);
}
void dsp(){
    if(front ==NULL){
        cout << "Empty Queue" << endl;
        return;
    }
    node *tmp = front;
    while(tmp != NULL){
        cout << tmp->n << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
int main(){
    int c;
    while(1){
        cout << "1 enque\n";
        cout << "2 deque\n";
        cout << "3 display\n";
        cout << "4 exit\n";
        cout << "Enter the choice: ";
        cin >> c;
        if(c==1) enq();
        else if(c==2) deq();
        else if(c==3) dsp();
        else return 0;
    }
}
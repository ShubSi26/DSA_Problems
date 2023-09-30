#include<iostream>
using namespace std;
struct node{
    int n;
    node *next;
}*front,*rear;
void ias(){
    node *t = new node();
    cout << "ENter the value: " ;
    cin >> t->n;
    if(rear == NULL){
        front = rear =t;
    }else{
        t->next = front;
        front = t;
    }
}
void iae(){ 
    node *t = new node();
    cout << "ENter the value: " ;
    cin >> t->n;
    if(rear == NULL){
        front = rear =t;
    }else{
        rear->next = t;
        rear = t;
    }
}
void dfs(){
    if(rear == NULL){
        cout << "Empty queue" << endl;
        return;
    }
    front =front->next;
    if(front == NULL){
        rear == NULL;
    }
}
void dfe(){
    if(rear == NULL){
        cout << "Empty queue" << endl;
        return;
    }
    node *t = front;
    node *pre;
    while(t != NULL){
        pre = t;
        t=t->next;
    }
    if(pre == front){
        front =NULL;
        rear = NULL;
    }
    rear = pre;
    pre->next = NULL;

}
void dsp(){
    if(rear == NULL){
        cout << "Empty queue" << endl;
        return;
    }
    node *t = front;
    while(t !=  NULL){
        cout << t->n << " ";
        t=t->next;
    }
    cout << endl;
}
int main(){
    int c;
    while(1){
        cout << "1 insert at start\n";
        cout << "2 insert at end\n";
        cout << "3 delete from start\n";
        cout << "4 delete from end\n";
        cout << "5 dispaly\n";
        cout << "6 exit\n";
        cout << "Enter the choice: ";
        cin >> c;
        if(c==1) ias();
        else if(c==2) iae();
        else if(c==3) dfs();
        else if(c==4) dfe();
        else if(c==5) dsp();
        else return 0;
    }
}
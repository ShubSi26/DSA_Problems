#include<iostream>
using namespace std;
#define n 5
int front = -1;
int rear = -1;
int queue[n];
void enq(){
    if(rear == 4) {
        cout << "Queue overflow" << endl;
        return;
    }
    int x;
    cout << "Enter the value: " ;
    cin >> x;
    if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;
    }else{
        rear++;
        queue[rear] = x;
    }
}
void dsp(){
    if(rear == -1){
        cout << "Queue is empty" <<endl;
        return;
    }
    for(int i=front;i<= rear;i++) cout << queue[i] << " ";
    cout << endl;
}
void deq(){
    if(front == -1){
        cout << "Queue is empty" << endl;
    }
    if(front == rear){
        front = rear = -1;
    }else{
        front++;
    }
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
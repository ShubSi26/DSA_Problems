#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};
struct node *temp,*head;
int main(){
    node* one = new node();
    node* two = new node();
    node* three = new node();

    one-> data = 21;
    two-> data = 22;
    three-> data = 23;
    head =  one;
    temp = one;
    one->next = two;
    two->next = three;
    while(temp != NULL){
        cout << temp->data << " ";
        temp=temp->next;
    }
}
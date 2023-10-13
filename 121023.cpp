#include<iostream>
using namespace std;

struct node
{
    int  n;
    node *l,*r;
};
node *newnode(int d){
    node *t= new node();
    t->n = d;
    t->l = NULL;
    t->r = NULL;
    return t;
}
void pre(node *t){
    if(t != NULL){
        cout << " " << t->n;
        pre(t->l);
        pre(t->r);
    }
}
void inord(node *t){
    if(t != NULL){
        pre(t->l);
        cout << " " << t->n;
        pre(t->r);
    }
}
void post(node *t){
    if(t != NULL){
        pre(t->l);
        pre(t->r);
        cout << " " << t->n;
    }
}
int main(){
    node *root = newnode(1);
    root->l = newnode(2);
    root ->r = newnode(3);
    root->l->l = newnode(4);
    root->r->l = newnode(9);
    root->r->l->r = newnode(10);
    root->l->l->r = newnode(11);
    root->l->r = newnode(8);
    cout << "preorder" << endl;
    pre(root);
    cout << endl;
    cout << "Inorder" << endl;
    inord(root);
    cout << endl << "Post order " << endl;
    post(root);
    
}

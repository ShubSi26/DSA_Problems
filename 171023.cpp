#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*l,*r;
    Node(int v) : data(v), l(NULL), r(NULL){}
};

Node* insert(Node *root, int v){
    if(root == NULL){
        return new Node(v);
    }
    if(v < root->data){
        root->l = insert(root->l,v);
    }else{
        root->r = insert(root->r,v);
    }
    return root;

}
void pre(Node *t){
    if(t != NULL){
        cout << " " << t->data;
        pre(t->l);
        pre(t->r);
    }
}
void inord(Node *t){
    if(t != NULL){
        pre(t->l);
        cout << " " << t->data;
        pre(t->r);
    }
}
void post(Node *t){
    if(t != NULL){
        pre(t->l);
        pre(t->r);
        cout << " " << t->data;
    }
}
bool search(Node *root,int v){
    if(root == nullptr) return false;
    if(root->data == v) return true;
    if(root->data > v){
        return search(root->l,v);
    }else{
        return search(root->r,v);
    }
}
Node* findmin(Node *root){
    if(root->l == NULL) return root;
        findmin(root->l);

}
Node* deleteNode(Node* root, int k){
    if (root == NULL)
        return root;
    if (root->data > k) {
        root->l = deleteNode(root->l, k);
        //return root;
    }
    else if (root->data < k) {
        root->r = deleteNode(root->r, k);
        //return root;
    }
    else if(1){
        if(root ->l == NULL){
            Node *t = root->r;
            delete root;
            return t;
        }else if(root->r == NULL){
            Node* t= root->l;
            delete root;
            return t;
        }
        Node *t = findmin(root->r);
        root->data = t->data;
        root->r = deleteNode(root->r,t->data);
    }
    return root;
}
int main(){
    Node *root = NULL;
    int x,r;
    cin >> x;
    root = insert(root,x);
    cin >> x;
    while(x > 0){
        root = insert(root,x);
        cin >> x;
    }
    cout << "Preorder" << endl;
    pre(root);
    cout << endl << "inord" << endl;
    inord(root);
    cout <<endl <<  "Postorder" << endl;
    post(root);
    cout << endl;
    cout << "enter value to delete: ";
    cin >> x;
    deleteNode(root,x);
    cout <<endl << "Preorder" << endl;
    pre(root);
    cout << endl << "inord" << endl;
    inord(root);
    cout << endl << "Postorder" << endl;
    post(root);
}
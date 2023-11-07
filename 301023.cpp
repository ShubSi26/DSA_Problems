//Maxheap
#include<iostream>
using namespace std;
#define MHS 100
int heap[MHS];
int heapSize = 0;
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b  =tmp;
}
void heapify(int index){
    int leftchild = 2*index +1;
    int rightchild = 2*index+2;
    int largest = index;
    if(leftchild < heapSize && heap[leftchild] > heap[largest]){
        largest = leftchild;
    }
    if(rightchild < heapSize && heap[rightchild] > heap[largest]){
        largest = rightchild;
    }
    if(largest != index){
        swap(&heap[index],&heap[largest]);
        heapify(largest);
    }
}
int main(){
    int n; cin >> n;
    for(int i=0;i<n;i++){
        cin >> heap[i];
        heapSize++;
    }
    for(int i=n/2+1;i>=0;i--){
        heapify(i);
    }
    for(int i=0;i<n;i++){
        cout << heap[i] << " ";
    }
}
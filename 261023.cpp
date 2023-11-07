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
void maxHeap(int index){
    while(index > 0 && heap[index] > heap[(index-1)/2]){
        swap(&heap[index], &heap[(index-1)/2]);
        index = (index-1)/2;
    }
}
void insert(int value){
    if(heapSize >= MHS){
        cout << "Heap is full" << endl;
        return;
    }
    heap[heapSize] = value;
    maxHeap(heapSize);
    heapSize++;
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
int deleteMax(){
    if(heapSize == 0){
        cout << "Heap is empty";
        return -1;
    }
    int deletedvalue = heap[0];
    heap[0] = heap[heapSize-1];
    heapSize--;
    heapify(0);
    return deletedvalue;
}
int main(){
    int n; cin >> n;
    int a;
   for(int i=0;i<n;i++){
        cin >> a;
        insert(a);
    }
    for(int i=0;i<n;i++){
        cout << heap[i] << " ";
    }
    cout << endl;
    int mn = deleteMax();
    while( mn != -1){
        cout << mn << " ";
        mn = deleteMax();
    }
}
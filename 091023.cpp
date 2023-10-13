#include<bits/stdc++.h>
using namespace std;

int partion(int arr[],int low, int high){
    int p = arr[low];
    int s = low;
    int end = high;
    while(s <= end){
        while(arr[s] <= p){
            s++;
        }
        while(arr[end] >= p && end >= s){
            end--;
        }
        if(end < s){
            break;
        }
        swap(arr[s],arr[end]);
    }
    swap(arr[low],arr[end]);
    return end;
}
void qs(int ar[],int l, int h){
    while(l<h){
        int p = partion(ar,l,h);
        qs(ar,l,p-1);
        qs(ar,p+1,h);
    }
}
int main(){
    int n; cin >> n;
    int ar[n];
    for(int i=0;i<n;i++) cin >> ar[i];
    qs(ar,0,n-1);
    for(int i=0;i<n;i++){
        cout << ar[i] << " ";
    }
}
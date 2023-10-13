#include<iostream>
using namespace std;
void merg(int ar[],int l, int m , int r){
    int arr[r-l+1];
    int i = l;
    int j = m+1;
    int ari = 0;
    while(i <= m && j <= r){
        if(ar[i] < ar[j]){
            arr[ari] = ar[i];
            ari++;
            i++;
        }else if(ar[i] > ar[j]){
            arr[ari] = ar[j];
            ari++;
            j++;
        }else{
            arr[ari] = ar[i];
            ari++;
            arr[ari] = ar[j];
            ari++;
            i++;
            j++;
        }
    }
    while(i <= m){
        arr[ari] = ar[i];
        ari++;
        i++;
    }
    while(j <=r){
        arr[ari] = ar[j];
        j++;
        ari++;
    }
    ari = 0;
    for(int i=l;i<=r;i++){
        ar[i] = arr[ari];
        ari++;
    }
}
void ms(int ar[],int l,int r){
    if(l < r){
        int m = (r+l)/2;
        ms(ar,l,m);
        ms(ar,m+1,r);
        merg(ar,l,m,r);
    }
}
int main(){
    int n; cin >> n;
    int ar[n];
    for(int i=0;i<n;i++) cin >> ar[i];
    ms(ar,0,n-1);
    for(int i=0;i<n;i++){
        cout << ar[i] << " ";
    }

}
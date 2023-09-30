#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter the size of array :";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n-1;i++){
        int mn =i;
        for(int j = i+1;j<n;j++){
            if(arr[j] < arr[mn]) mn = j;
        }
        if(arr[i] != arr[mn]){
            int tmp = arr[i];
            arr[i] = arr[mn];
            arr[mn] = tmp;}
    }
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}
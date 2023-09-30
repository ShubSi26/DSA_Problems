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
    for(int i=1;i<n;i++){
        int idx = i-1;
        while(idx >=0 and arr[idx] > arr[idx+1]){
            int t = arr[idx];
            arr[idx] = arr[idx + 1];
            arr[idx+1] = t;
            idx--;
        }
    }
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}
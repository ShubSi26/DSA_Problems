#include<iostream>
using namespace std;
void toh(int n,char source,char aux, char dest){
    if(n==1){
        cout << source << "->" << dest << endl;
        return;
    }
    toh(n-1,source,dest,aux);
    cout << source << " ->" << dest << endl;
    toh(n-1,aux,source,dest);
}
int main(){
    int n; cin >> n;
    toh(n,'A','B','C');
}
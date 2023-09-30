#include<bits/stdc++.h>
#include<stack>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    stack<string> st;
    for(int i=0;i<s.length();i++){
        if(s[i]>='a' && s[i] <= 'z'){
            string o(1,s[i]);
            st.push(o);
        }
        else{
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();
            st.push("(" + b+s[i]+a+")");
        }
    }
    cout << st.top();
}
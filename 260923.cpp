#include<iostream>
#include<stack>
using namespace std;
int pre(char c){
    if(c == '^') return 3;
    if(c == '/' || c== '*') return 2;
    if(c== '+' || c=='-') return 1;
    else return -1;
}
int main(){
    string s;
    cin >> s;
    string ans;
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')) ans+=s[i];
        else if(s[i] == '(') st.push('(');
        else if(s[i] == ')'){
            while(st.top() != '('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }else{
            while(!st.empty() && pre(s[i]) <= pre(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    cout << ans;
}
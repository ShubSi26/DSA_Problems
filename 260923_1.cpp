#include<bits/stdc++.h>
#include<stack>
using namespace std;
int pre(char c){
    if(c == '^') return 3;
    if(c == '/' || c== '*') return 2;
    if(c== '+' || c=='-') return 1;
    else return -1;
}
string inftopof(string s){
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
    return ans;
}

int main(){
    string s;
    cin >> s;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.length();i++){
        if(s[i] == '(') s[i] = ')';
        else if(s[i] == ')') s[i] ='(';
    }
    string ans = inftopof(s);
    reverse(ans.begin(),ans.end());
    cout << ans;
}
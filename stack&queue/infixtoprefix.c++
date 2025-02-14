// C++ program to convert infix to prefix
#include <bits/stdc++.h>
using namespace std;

int prio(char c){
    if(c=='^')return 3;
    else if(c=='*' || c=='/')return 2;
    else if(c=='+' || c=='-')return 1;
    else return -1;
}
int main() {
        // string s="a+(b/c)^d^e+f";
        string s="(a+b)*c-d+f";
        stack<char> st;
        string ans="";
        
        reverse(s.begin(), s.end());  
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                s[i] = ')';
            } else if (s[i] == ')') {
                s[i] = '(';
            }
        }
        for(int i=0; i<s.size(); i++){
            
            if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
                ans+=s[i];
            }
            else if(s[i]=='('){
                st.push('(');
            }
            else if(s[i]==')'){
                while( !st.empty() && st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else {
                if(s[i]=='^'){
                    while(!st.empty() && prio(s[i])<=prio(st.top())){
                        ans+=st.top();
                        st.pop();
                    } 
                }else{
                    while(!st.empty() && prio(s[i])<prio(st.top())){
                        ans+=st.top();
                        st.pop();
                    }
                }
                st.push(s[i]);
            }
        }
        
        while(!st.empty()){
            
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());  
        for(int i=0;i<s.size();i++)
        cout<<ans[i];

        return 0;
}

#include<bits/stdc++.h>
using namespace std;


int main(int argc, char *a[])
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  long long t;
  cin>>t;
  while(t--){
    string str;
    cin>>str;
    int flag=1;
    stack<char> st;
    for (int i = 0; i < str.size(); ++i)
    {
      // if(flag==0)break;
      if(str[i]=='('|| str[i]=='['|| str[i]=='{')
        st.push(str[i]);
      else{
        if(st.empty()){
          cout<<"false\n";
          flag=0;
          break;
        }
        if(st.top()=='(' && str[i]==')') st.pop();
        else if(st.top()=='[' && str[i]==']') st.pop();
        else if(st.top()=='{' && str[i]=='}') st.pop();
        else{
          cout<<"false\n";
          flag=0;
          break;
        }
      }
    }
    if(flag){
      if(!st.empty())
        cout<<"flase\n";
      else
        cout<<"true\n";
    }
  }
  return 0;
}
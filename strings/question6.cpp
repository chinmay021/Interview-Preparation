#include <bits/stdc++.h> 
using namespace std;  

set<string> s;
void print_subs(string input,string output){
  if(input.length()==0)
  {
    // cout<<output<<endl;
    s.insert(output);
    return;
  }
  //input.substr(1)=returns substring from [1,n-1] eg: abcd --> bcd
  print_subs(input.substr(1),output);//excluding the alphabet
  print_subs(input.substr(1),output+input[0]); //including the alphabet
}

int main() 
{ 
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  string str;
  cin>>str;
  print_subs(str,"");
  for(auto i : s)
  {
    cout<<i<<endl;
  }
  return 0; 
} 

# include <bits/stdc++.h> 
using namespace std;  
int main() 
{ 
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  string str; 
  cin>>str;
  set<char> s;
  for(int i=0; i<str.length(); ++i)
  {
    s.insert(str[i]);
  }
  for (auto i = s.begin(); i != s.end(); ++i)
  {
    cout<<*i<<" ";
  }
  return 0; 
} 
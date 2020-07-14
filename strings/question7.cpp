#include <bits/stdc++.h> 
using namespace std;  

vector<string> v;

void print_permutations(string str,int l,int r){
    if(l==r){
      //cout<<str<<" ";
      v.push_back(str);
    }
    else{
      for (int i = l; i <= r; ++i)
      {
        swap(str[l],str[i]);
        print_permutations(str,l+1,r);
        swap(str[l],str[i]);
      }
    }
}

int main() 
{ 
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin>>t;
  while(t--)
  {
    string str;
    cin>>str;
   // sort(str.begin(),str.end());
    print_permutations(str,0,str.length()-1);
    sort(v.begin(),v.end());
    for (auto i = v.begin(); i != v.end(); ++i)
    {
      cout<<*i<<" ";
    }
    cout<<endl;
    v.clear();
  }
  
  return 0; 
} 
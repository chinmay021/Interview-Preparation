#include<bits/stdc++.h>
using namespace std;
int main()
{
  freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
  int t;
  cin>>t;
  while(t--){
    int n,money_spent;
    cin>>n>>money_spent;
    int min_def=999,min_for=999;
    int  a[n],b[n];
    for (int i = 0; i < n; ++i)
    {
      cin>>a[i];
    }
    for (int i = 0; i < n; ++i)
    {
      cin>>b[i];
    }
    for (int i = 0; i < n; ++i)
    {
      if(b[i]==0)
      {
        if(a[i]<min_def)
        {
          min_def=a[i];
        }
      }
      else if(b[i]==1)
      {
        if(a[i]<min_for)
        {
          min_for=a[i];
        }
      }
    }
    if(money_spent+min_for+min_def<=100)
      cout<<"yes"<<endl;
    else
      cout<<"no"<<endl;
  }
  return 0;
}
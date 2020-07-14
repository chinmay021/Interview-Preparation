#include<bits/stdc++.h>
using namespace std;


int main(int argc, char *a[])
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  long long t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
      cin>>v[i];
    }
    int index=-1;
    for (int i = n-2; i >=0 ; --i)
    {
      if(v[i]<v[i+1])
      {
        index=i;
        break;
      }
    }
    if(index!=-1)
    {
      int index2=index+1;
      for (int i = index+1; i < n; ++i)
      {
        if(v[i]>v[index])
          index2=i;
      }
      swap(v[index],v[index2]);
    }

    sort(v.begin()+1+index, v.end());
    for (auto it = v.begin(); it != v.end(); ++it)
    {
      cout<<*it<<" ";
    }
    cout<<endl;
  }
  return 0;
}
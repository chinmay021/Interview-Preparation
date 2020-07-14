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
      long long count0=0,count1=0,count=0;
      for (int i = 0; i < str.size(); ++i)
      {
          if(str[i]=='0')
              count0++;
          else if(str[i]=='1')
              count1++;
          if(count1==count0)
              count++;
      }
      if(count1 != count0)
        cout<<"-1\n";
      else
        cout<<count<<endl;
    }
    return 0;
}

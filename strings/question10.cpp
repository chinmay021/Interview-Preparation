#include<bits/stdc++.h>
using namespace std;
int main(int argc, char *a[])
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  long long t;
  cin>>t;
  while(t--){
    string str,result;
    cin>>str;
    int n=str.size();
    set<char> s;
    for (int i = 0; i < str.size(); ++i)
    {
      s.insert(str[i]);
    }
    map<char, int> mymap;
    for (auto it = s.begin(); it != s.end(); ++it)
    {
      mymap[*it]++;
    }
    // for (auto it = mymap.begin(); it!=mymap.end(); ++it)
    // {
    //   cout<<it->first<<" "<<it->second<<" ";
    // }
    // cout<<endl;
    int left=0;
    int count=0;
    int min_length=9999999;
    for (int right = 0; right < str.size(); ++right)
    {
      if (--mymap[str[right]]>=0)
      {
        ++count;
        //cout<<str[right]<<" ";
      }
      while(count==s.size()){

        if (min_length>right-left+1)
        {
          min_length=right-left+1;
          result=str.substr(left,right);
        }
        if(++mymap[str[left]]>0)
          --count;
        ++left;
      }
    }
    cout<<min_length<<endl;
   }
  return 0;
}
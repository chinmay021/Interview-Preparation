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
    int n=str.size();
    std::map<char, int> mymap;
    int max_count=0;
    for (int i = 0; i < n; ++i)
    {
    	mymap[str[i]]++;
    	if(mymap[str[i]]>max_count)
    		max_count=mymap[str[i]];
    }
    if(n-max_count>=max_count-1)
    	cout<<"1\n";
    else
    	cout<<"0\n";
  }
  return 0;
}

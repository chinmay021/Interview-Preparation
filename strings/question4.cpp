# include <bits/stdc++.h> 
using namespace std;  
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
    int len=str.length();
    int low,high,start=0,maxlength=1;
    for(int i=1; i<len; ++i)
    {
      //for even length e.g [a,b,b,a]
      low=i-1;
      high=i;
      while(str[low]==str[high] && low>=0 && high<len)
      {
        if(high-low+1>maxlength)
        {
          start=low;
          maxlength=high-low+1;
        }
        high++;
        low--;
      }
      //for odd length e.g[a,b,b,b,a]
      low=i-1;
      high=i+1;
      while(str[low]==str[high] && low>=0 && high<len)
      {
        if(high-low+1>maxlength)
        {
          start=low;
          maxlength=high-low+1;
        }
        high++;
        low--;
      }
    }
    for (int i = start; i<= start+maxlength-1; ++i)      
    {
      cout<<str[i];
    }
    cout<<endl;
    
  }
  return 0; 
} 
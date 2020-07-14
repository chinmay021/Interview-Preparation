#include<bits/stdc++.h>
using namespace std;

bool isvalid(string str)
{

  if(str.length()>3)
    return false;
  if(str[0]=='0'&& str.length()>1)
    return false;
  if(str.length()>1 && stoi(str)!=0 && str[0]=='0')
      return false;
  int num=stoi(str);
  return(num>=0 && num<=255);
}
int main(int argc, char *a[])
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  long long t;
  cin>>t;
  while(t--){
    string str;
    cin>>str;
    int len=str.length();
    vector<string> result;
    for (int i = 1; i < 4 && i< len; ++i)
    {
      string first=str.substr(0,i);
      if(!isvalid(first))
        continue;
      for (int j = 1; j < 4 && j+i<len; ++j)
      {
        string second=str.substr(0+i,j);//i 0+i for understanding
        if(!isvalid(second))
          continue;
        for (int k = 1; k < 4 && i+j+k<len; ++k)
        {
          string third=str.substr(i+j,k);
          string fourth=str.substr(i+j+k);//to last
          if(isvalid(third) && isvalid(fourth))
          {
            string ip=first+"."+second+"."+third+"."+fourth;
            result.push_back(ip);
          }
        }
      }
    }
    for (auto it = result.begin(); it != result.end(); ++it)
    {
      cout<<*it<<"\t";
    }
    cout<<endl;
   }
  return 0;
}
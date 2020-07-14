# include <bits/stdc++.h> 
using namespace std;  

int lcs(string str,int n)
{
  int dp[n+1][n+1];
  for (int i = 0; i <= n; ++i)
  {
    for (int j = 0; j <= n; ++j)
    {
      dp[i][j]=0;
    }
  }
  for (int i = 1; i <= n; ++i)
  {
    for (int j= 1; j <= n; ++j)
    {
      if(str[i-1] == str[j-1] && i != j)
        dp[i][j] = 1 + dp[i-1][j-1];
      else
        dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    }
  }
  return dp[n][n];
}

int main() 
{ 
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    string str;
    cin>>str;
    cout<<lcs(str,n)<<endl;
  }
  return 0; 
} 
#include<bits/stdc++.h>
using namespace std;
int minimum(int a,int b, int c)
{
    return min(min(a,b),c);
}
int editdistanceDP(string str1,string str2,int m,int n)
{
    int dp[m+1][n+1];
    for (int i = 0; i <= m; ++i)
    {
        for (int j = 0; j <=n; ++j)
        {
            if(i==0)
                dp[i][j]=j;
            else if(j==0)
                dp[i][j]=i;
            else if(str1[i-1]==str2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=1+minimum(dp[i-1][j-1],dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[m][n];
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  long long t;
  cin>>t;
  while(t--){
    int m,n;
    cin>>m>>n;
    string word1,word2;
    cin>>word1;
    cin>>word2;
    cout<<editdistanceDP(word1,word2,m,n);
   }
  return 0;
}
#include <bits/stdc++.h> 
using namespace std; 
 
 int count_palindrome_subsequence(string str)
 {
    int n=str.length();
    int dp[n+1][n+1];
    memset(dp,0,sizeof(dp));

    for (int i = 0; i < n; ++i)
    {
        dp[i][i]=1;
    }

    for (int l = 2; l <= n; ++l)
    {
        for (int i = 0; i < n; ++i)
        {
            int j=l+i-1;
            if(str[i]==str[j])
            {
                dp[i][j]=dp[i][j-1]+dp[i+1][j]+1;
            }
            else
            {
                dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
            }
        }
    }
    return dp[0][n-1];
 }
 
int main() 
{ 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
       string s;
       cin>>s;
       cout<<count_palindrome_subsequence(s)<<endl;
    }
    return 0;
}
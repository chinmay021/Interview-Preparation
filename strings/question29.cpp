#include <bits/stdc++.h> 
using namespace std; 
bool search(char board[100][100],string word, int i,int j,int count,int n, int m)
{
  if(count==word.length())
    return 1;
  if(i<0 || i>=n || j<0 || j>=m || board[i][j]!=word[count])
  {
    return 0;
  }
  char temp=board[i][j];
  board[i][j]=' ';
  bool found=(search(board,word,i-1,j-1,count+1,n,m)
              || search(board,word,i-1,j,count+1,n,m)
              || search(board,word,i-1,j+1,count+1,n,m)
              || search(board,word,i,j-1,count+1,n,m)
              || search(board,word,i,j+1,count+1,n,m)
              || search(board,word,i+1,j-1,count+1,n,m)
              || search(board,word,i+1,j,count+1,n,m)
              || search(board,word,i+1,j+1,count+1,n,m));
  board[i][j]=temp;
  return found;
}


int main() 
{ 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
      int n,m,count=0;
      cin>>n>>m;
      char board[100][100];
      string word;
      for (int i = 0; i < n; ++i)
      {
        for (int j = 0; j < m; ++j)
        {
          cin>>board[i][j];
        }
      }
      cin>>word;
     // cout<<word;
      for (int i = 0; i < n; ++i)
      {
        for (int j = 0; j < m; ++j)
        {
          if(board[i][j]==word[0] && search(board,word,i,j,0,n,m))
          {
            count++;
          }
        }
      }
      cout<<count<<endl;
    }
    return 0;
}
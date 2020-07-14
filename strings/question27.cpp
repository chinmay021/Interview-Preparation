#include <bits/stdc++.h> 
using namespace std; 

int count_flips(string s, char expected){
    int flipcounts=0;
    for (int i = 0; i < s.length(); ++i)
    {
        if(s[i]!=expected)
            flipcounts++;
        expected = (expected == '0' ?'1':'0');
    }
return flipcounts;
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
       cout<<min(count_flips(s,'0'),count_flips(s,'1'))<<endl;
    }
    return 0;
}
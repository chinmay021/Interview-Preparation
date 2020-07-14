#include <bits/stdc++.h> 
using namespace std; 
 
 
int main() 
{ 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int flag=1;
        std::map<char, bool> mymap;
        for (int i = 0; i < s.size(); ++i)
        {
            mymap[s[i]]=false;

        }
        for (int i = 0; i < s.size(); ++i)
        {
            if(mymap[s[i]]==true){
                cout<<s[i]<<endl;
                flag=0;
                break;
            }
            else
                mymap[s[i]]=true;
        }
        if(flag)
            cout<<"-1\n";
    }
    return 0;
} 
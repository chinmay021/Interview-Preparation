#include <bits/stdc++.h> 
using namespace std; 
 
 
int main() 
{ 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,first_max=INT_MIN,second_max=INT_MIN;
        cin>>n;
        std::vector<string> v(n);
        std::map<string, int> mymap;
        for (int i = 0; i < n; ++i)
        {
            cin>>v[i];
            mymap[v[i]]++;

         //   cout<<" EE";
        }
        for (auto it = mymap.begin(); it != mymap.end(); ++it)
        {
            if(it->second>first_max)
            {
                second_max=first_max;
                first_max=it->second;
            }
            else if(it->second < first_max && it->second >second_max)
            {
                second_max=it->second;
            }
        }
        for (auto it = mymap.begin(); it != mymap.end(); ++it)
        {
            if(it->second == second_max)
                cout<<it->first<<endl;
        }

    }
} 
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        long long n,flag=1;
        cin>>n;
        std::vector<int> v(n);
        for (int i = 0; i < n; ++i)
        {
            cin>>v[i];
        }
        std::map<long long , long long> mymap;
        for (int i = 0; i < n; ++i)
        {
            mymap[v[i]]++;
        }
        for (int i = 0; i < n; ++i)
        {
             if(mymap[v[i]]>1)
             {
                cout<<i+1<<endl;
                flag=0;
                break;
             }
        }
        if(flag)
        {
            cout<<"-1\n";
        }      
    }
    return 0;
}
       
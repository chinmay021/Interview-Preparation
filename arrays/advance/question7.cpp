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
        long long n1,n2,n3,flag=1;
        cin>>n1>>n2>>n3;
        std::map<long, long> mymap;
        std::vector<long long> a(n1),b(n2),c(n3);
        for (int i = 0; i < n1; ++i)
        {
            cin>>a[i];
            mymap[a[i]]=1;
        }
        for (int i = 0; i < n2; ++i)
        {
            cin>>b[i];
            if(mymap[b[i]]==1)
                mymap[b[i]]=2;
        }
        for (int i = 0; i < n3; ++i)
        {
            cin>>c[i];
            if(mymap[c[i]]==2)
                mymap[c[i]]=3;
        }
        for (auto it=mymap.begin(); it!=mymap.end(); ++it)
        {
            if(it->second==3)
            {
                cout<<it->first<<" ";
                flag=0;
            }
        }
        if(flag)
        {
            cout<<"-1\n";
        }
        else
        {
            cout<<endl;
        }
    }
    return 0;
}
       
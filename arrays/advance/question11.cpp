#include <bits/stdc++.h>
using namespace std;
// //void rotate(vector<int> &v, std::vector<int>::iterator i=v.begin(), std::vector<int>::iterator  j=v.end())
// {
//     cout<<"hello";
//     v.insert(i,*j);
//     v.erase(j);
//     cout<<"hello";
//     for (auto ik = v.begin(); ik != v.end(); ++ik)
//     {
//         cout<<*ik<<" ";
//     }
// }
int main() {
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        long long n,k,temp;
        cin>>n;
        std::vector<int> v;
        for (int i = 0; i < n; ++i)
        {
            cin>>k;
            v.push_back(k);
        }
        // for (auto i = v.begin(); i != v.end(); ++i)
        // {
        //     cout<<*i<<" ";
        // }
        // cout<<endl;
        for (auto it = v.begin(); it != v.end(); ++it)
        {
            int index=distance(v.begin(),it),flag=0;
            if(index%2==0 && *it<0)
            {
                auto j = it;
                for (; j != v.end(); ++j)
                {
                    if(*j>=0)
                    {
                        flag=1;
                        break;
                        
                    }
                }
                if(flag)
                {
                    v.insert(it,*j);
                    v.erase(j+1);
                }
                // for (auto i = v.begin(); i != v.end(); ++i)
                // {
                //     cout<<*i<<" ";
                // }
                // cout<<endl;
            }
            flag=0;
            if(index%2!=0 && *it>=0)
            {
                auto j = it;
                for (; j != v.end(); ++j)
                {
                    if(*j<0)
                    {
                        flag=1;
                        break;
                        
                    }
                }
                if(flag)
                {
                    v.insert(it,*j);
                    v.erase(j+1);
                }
            //     for (auto i = v.begin(); i != v.end(); ++i)
            //     {
            //         cout<<*i<<" ";
            //     }
            //     cout<<endl;
             }
        }
        for (auto i = v.begin(); i != v.end(); ++i)
        {
            cout<<*i<<" ";
        }
        cout<<endl;

    }
    return 0;
}
       
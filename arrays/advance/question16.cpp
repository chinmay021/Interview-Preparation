#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--)
    {
    	long long n,longest_seq=0;
        cin>>n;
        std::vector<int> v(n);
        std::map<int , bool> mymap;
        for (int i = 0; i < n; ++i)
        {
            cin>>v[i];
            mymap[v[i]]=true;
        }
        for (int i = 0; i < n; ++i)
        {
            long long curr,count=0;
            if(!mymap[v[i]-1])
            {
                curr=v[i];
                while(mymap[curr])
                {
                    count++;
                   // cout<<count;
                    curr++;
                }
                if (count>longest_seq)
                {
                    longest_seq=count;
                }
            }
        }
        cout<<longest_seq<<endl;
        
    } 

	return 0;
}
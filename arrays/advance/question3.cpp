#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	// code from here
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,l,temp,count=0;
        std::vector<int> v;
        for(int i=0; i<n; ++i)
        {
            cin>>k;
            v.push_back(k);
        }
        std::vector<int>::iterator it;
        for(int i=0; i<n; ++i)
        {
            temp=k-v[i];
            it=find(v.begin(),v.end(),temp);
            if(it!=v.end())
            {
                count++;
            }
        }
        cout<<count;
    }

	return 0;
}
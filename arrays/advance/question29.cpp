#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	// code from here
    int t;
    cin>>t;
     while(t--)
     {
        long long m,n,flag=1;
        cin>>m>>n;
        long long arr1[m],arr2[n];
        std::map<int , bool> mymap;
        for (int i = 0; i < m; ++i)
        {
        	cin>>arr1[i];
        	mymap[arr1[i]]=true;
        }
        for (int i = 0; i < n; ++i)
        {
        	cin>>arr2[i];
        }
        for (int i = 0; i < n; ++i)
        {
        	if(!mymap[arr2[i]])
        	{
        		cout<<"No\n";
        		flag=0;
        		break;
        	}
        }
        if(flag)
        {
        	cout<<"Yes\n";
        }
     }
	return 0;
}
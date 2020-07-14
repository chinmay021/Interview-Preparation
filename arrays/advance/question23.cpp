#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--)
    {
        long long  n;
        cin>>n;
        long long arr[n+2];
        for(int i=0; i<n+2; i++)
            cin>>arr[i];
        for (int i = 0; i < n+2; ++i)
        {
        	int index=abs(arr[i])%n;
        	if (arr[index]<0)
        	{
        		cout<<abs(index)<<" ";
        	}
        	else
        		arr[index]=-arr[index];
        }
        cout<<endl;
    }        
    return 0;
}
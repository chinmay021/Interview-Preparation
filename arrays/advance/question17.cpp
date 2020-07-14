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
    	long long n,flag=1;
        cin>>n;
        long long arr[n];
        for (int i = 0; i < n; ++i)
        {
            cin>>arr[i];
        } 
        if(n<1) cout<<"-1\n",flag=0;
        if(n==1) cout<<arr[0],flag=0;
        long long low=0;
        long long high=n-1;
        while(low<high)
        {
            long long mid=low+(high-low)/2;
            if(mid>0 && arr[mid]<arr[mid-1])
            {
                cout<<arr[mid]<<endl;
                flag=0;
                break;
            }
            else if(arr[low]<= arr[mid] && arr[mid]> arr[high])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        if(flag)
        {
            cout<<arr[low]<<endl;
        }
    } 

	return 0;
}


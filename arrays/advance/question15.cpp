#include<bits/stdc++.h>
using namespace std;
// long long maximum(long long a, long long b)
// {
//     if(a>b)
//         return a;
//     else
//         return b;
// }

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--)
    {
    	long long n;
        cin>>n;
        long long arr[n];
        for (int i = 0; i < n; ++i)
        {
            cin>>arr[i];
        }
        long long current_max=arr[0];
        long long current_min=arr[0];
        long long final_max=arr[0];
        for (int i = 1; i < n; ++i)
        {
            long long temp=current_max;
            current_max=max(current_max*arr[i],max(current_min*arr[i],arr[i]));
            current_min=min(current_min*arr[i],min(temp*arr[i],arr[i]));
            if(current_max>final_max)
            {
                final_max=current_max;
            }

        }
        cout<<final_max<<endl;

    }
	return 0;
}
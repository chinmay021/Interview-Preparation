#include<bits/stdc++.h>
using namespace std;
long long maximum(long long a, long long b)
{
    if(a>b)
        return a;
    else
        return b;
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--)
    {
    	long long n,sum=0,global_max,local_max;
        cin>>n;
        std::vector<int> v(n);
        for (int i = 0; i < n; ++i)
        {
            cin>>v[i];
        }
        global_max=v[0];
        local_max=v[0];
        for (int i = 1; i < n; ++i)
        {
            // sum+=v[i];
            local_max=maximum(v[i],local_max+v[i]);
          //  cout<<local_max<<endl;
            if(local_max>global_max)
            {
                global_max=local_max;
            }
        }
        cout<<global_max<<endl;

    }
	return 0;
}
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
        int k,n;
        cin>>n;
        std::vector<int> v(n);
        for (int i = 0; i < n; ++i)
        {
            cin>>v[i];
        }
        if(n<=1)            
            return 0;
        if(v[0] == 0)
        {     
            cout<<"-1\n";
            continue;
        }
        int ladder=v[0];
        int stairs=v[0];
        int jumps=1;
        for (int i = 1; i < n; ++i)
        {
            if(i == n-1)  
                cout<<jumps<<endl;
           //if(i+v[i]>ladder)
              //  ladder=i+v[i];
            ladder= max(ladder, i+v[i]); 
            stairs--;
            if(stairs==0)
            {
                ++jumps;
                if(i>= ladder)//
                {
                    cout<<"-1\n";// If ladder is less than equal to 
                    break;       //i we can't move further, return -1                    
                }
                stairs=ladder-i;
            }
        }
    }

	return 0;
}
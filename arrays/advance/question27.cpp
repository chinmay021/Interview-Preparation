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
        int r,c;
        double sum=0;
        cin>>r>>c;
        int a[r][c];
        for (int i = 0; i < r; ++i)
        {
            for (int i = 0; i < c; ++i)
            {
                cin>>a[r][c];
                sum+=a[r][c];
            }
        }
        int answer=round(sum/(r*c));
        cout<<answer<<endl;
    }
    return 0;
}
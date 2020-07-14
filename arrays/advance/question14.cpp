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
        int n;
        cin>>n;
        int arr[500]={};
        arr[0]=1;
        int arr_size=1;
        for (int x = 2; x <= n; ++x)
        {
            int carry=0;
            for (int i = 0; i < arr_size; ++i)
            {
                int product=arr[i]*x+carry;
                arr[i]=product%10;
                carry=product/10;
            }
            while(carry)
            {
                arr[arr_size++]=carry%10;
                carry=carry/10;
            }
        }
        for (int i = arr_size-1; i >=0; --i)
        {
            cout<<arr[i];
        }

    }
	return 0;
}
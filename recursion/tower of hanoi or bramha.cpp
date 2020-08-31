#include <bits/stdc++.h>
using namespace std;
void TOH(int n, int source, int destination, int helper, int &moves)
{
    moves++;
    if (n == 1)
    {
        cout << "move disk " << n << " from rod " << source << " to rod " << destination << "\n";
        return;
    }
    TOH(n - 1, source, helper, destination, moves);
    cout << "move disk " << n << " from rod " << source << " to rod " << destination << "\n";
    TOH(n - 1, helper, destination, source, moves);
}
int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int moves = 0;
        TOH(n, 1, 3, 2, moves);
        cout << moves;
        cout << "\n";
    }
    return 0;
}
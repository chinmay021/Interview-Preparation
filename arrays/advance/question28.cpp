#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	// code from here
	int t;
	cin >> t;
	while (t--)
	{
		int m, n;
		cin >> m >> n;
		int ar[m][n] = {{0}};
		int i = 0;
		int j = 0;
		int row = 0;
		int col = 0;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> ar[i][j];
			}
		}
		while (row < m && col < n)
		{
			//Printing 1st row
			for (i = col; i < n; i++)
			{
				printf("%d ", ar[row][i]);
			}
			row++;

			//Printing last col
			for (i = row; i < m; i++)
			{
				printf("%d ", ar[i][n - 1]);
			}
			n--;

			//Printing last row
			if (row < m)
			{
				for (i = n - 1; i >= col; --i)
				{
					printf("%d ", ar[m - 1][i]);
				}
				m--;
			}

			//Printing first col
			if (col < n)
			{
				for (i = m - 1; i >= row; --i)
				{
					printf("%d ", ar[i][col]);
				}
				col++;
			}
		}

		printf("\n");
	}
	return 0;
}
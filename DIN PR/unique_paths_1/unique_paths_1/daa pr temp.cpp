#include <iostream>
using namespace std;
int N, M, d[128][128];

int calc(int m, int n) {
	for (int i = 1; i <= n; i++) 
	{
		d[1][i] = 1;
	}
	for (int i = 1; i <= m; i++)
	{
		d[i][1] = 1;
	}

	for (int r = 2; r <= m; r++)
	{
		for (int c = 2; c <= n; c++)
		{
			d[r][c] = d[r - 1][c] + d[r][c - 1];
		}
	}
	return d[m][n];
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	cout << calc(n, m) << endl;

	return 0;
}

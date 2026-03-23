#include <iostream>


using namespace std;
int n, m, d[128][128], g[128][128];

int calc(int x, int y) { // n rows, m cols, x is for row, y is for column
	if (x > n - 1 || y > m - 1) return 0;
	if (g[x][y]) return 0;
	if (x == n - 1 && y == m - 1) return 1;

	if (d[x][y]) return d[x][y];

	return d[x][y] = calc(x + 1, y) + calc(x, y + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n>> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> g[i][j];
		}
	}
	cout << calc(0, 0);

	return 0;
}

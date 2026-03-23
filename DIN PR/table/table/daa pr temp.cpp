#include <iostream>
#include <climits>
using namespace std;
#define MAX 1010

int m, n;
int t[MAX][MAX], d[MAX][MAX];

int calc(int c, int r) {
	if (r > m - 1 || c > n - 1) return INT_MAX;
	if (r < 0 || c < 0) return INT_MAX;
	if (c == n - 1) return t[r][c];
	
	if (d[r][c] != INT_MAX) return d[r][c];
	d[r][c] = t[r][c] + min(min(calc(c + 1, r + 1), calc(c + 1, r - 1)), calc(c +1, r));
	return d[r][c];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> t[i][j];
		}
		fill(d[i], d[i] + n + 2, INT_MAX);
	}

	int ans = INT_MAX;
	for (int i = 0; i < m; i++) {
		ans = min(ans, calc(0, i));
	}
	cout << ans << endl;
	return 0;
}

/*
4 6
3 4 1 2 8 6
6 1 8 2 7 4
5 9 3 9 9 5
8 4 1 3 2 6
-----
.: 17

*/
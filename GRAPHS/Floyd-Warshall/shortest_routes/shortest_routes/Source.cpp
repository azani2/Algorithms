#include <iostream>
#include <climits>
#include <queue>
using namespace std;

#define MAX 500
int n, m, q, x, y;
long d[MAX + 5][MAX + 5], w;
queue<pair<int, int>> tasks;

void computeShortestPaths() {
	for (int k = 1; k <= n; k++) {
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				if (d[a][b] > d[a][k] + d[k][b])
					d[a][b] = d[a][k] + d[k][b];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> q;

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++)
			d[i][j] = d[j][i] = INT_MAX/2;
	}

	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		d[x][y] = min(d[x][y], w);
		d[y][x] = min(d[y][x], w);
	}

	computeShortestPaths();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << d[i][j] << " ";
		cout << endl;
	}

	while (q--) {
		cin >> x >> y;
		tasks.push({ x,y });
	}
	while (!tasks.empty()) {
		x = tasks.front().first;
		y = tasks.front().second;
		tasks.pop();
		cout << ((d[x][y] == INT_MAX) ? ( - 1) : d[x][y]) << endl;
	}
}
#include <iostream>
#include <queue>
using namespace std;
#define MAX 1005

int n, m, k, maxWidth[MAX][MAX], x, y, w;
queue<pair<int, int>>tasks;

void printMatrix() {
	cout << "------------------" << endl;
	for (int k = 1; k <= n; k++) {
		for (int a = 1; a <= n; a++)
			cout << maxWidth[k][a] << " ";
		cout << endl;
	}
	cout << "------------------" << endl << endl;
}

void computeMaxWidths() {
	for (int k = 1; k <= n; k++) {
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= a; b++) {
				int w = min(maxWidth[a][k], maxWidth[k][b]);
				if (w > maxWidth[a][b])
					maxWidth[a][b] = maxWidth[b][a] = w;
			}
		}
	}
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		maxWidth[x][y] = max(maxWidth[x][y], w);
		maxWidth[y][x] = max(maxWidth[y][x], w);
	}
	computeMaxWidths();
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		tasks.push({ x,  y});
	}
	while (!tasks.empty()) {
		x = tasks.front().first;
		y = tasks.front().second;
		tasks.pop();
		cout << maxWidth[x][y] << endl;
	}

	

	return 0;
}


//still exceeds time limit
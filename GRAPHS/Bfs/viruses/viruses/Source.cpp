#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAXV = 1e4 + 5;

int n, m;
bool matrix[105][105];

bool visited[MAXV];
vector<int> adj[MAXV];
queue<int> q;

void bfs(int u) {
	q.push(u);
	visited[u] = true;
	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (auto v : adj[u]) {
			if (visited[v]) continue;
			visited[v] = true;
			q.push(v);
		}
	}
}

int ccomponents() {
	int counter = 0;
	for (int i = 1; i <= n * m; i++) {
		if (!visited[i]) {
			counter++;
			bfs(i);
		}
	}
	return counter;
}

int id(int x, int y) {
	return (x - 1) * m + y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	int k, x, y;
	cin >> k;

	for ( int i = 0; i < k; i++)
	{
		cin >> x >> y;
		matrix[x][y] = true;
		visited[id(x, y)] = true;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) {
			if (matrix[i][j]) continue;
			if (i > 1 && matrix[i - 1][j] == 0) {
				adj[id(i, j)].push_back(id(i - 1, j));
				adj[id(i-1, j)].push_back(id(i, j));
			}
			if (j > 1 && matrix[i][j - 1] == 0) {
				adj[id(i, j)].push_back(id(i, j - 1));
				adj[id(i, j - 1)].push_back(id(i, j));
			}
		}
	}
	cout << ccomponents() << endl;

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 1005;

vector<int> adj[MAXN];
bool visited[MAXN];
queue<int> q;

int n, m;

void bfs(int v) {
	q.push(v);
	visited[v] = true;

	while (!q.empty()) {
		v = q.front();
		cout << v << " ";
		q.pop();
		for (auto u : adj[v]) {
			if (visited[u]) continue;
			visited[u] = true;
			q.push(u);
		}
	}
	cout << endl;
}

int main() {
	cin >> n >> m;

	int i, u, v;

	for (i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (i = 0; i < n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	bfs(0);

}
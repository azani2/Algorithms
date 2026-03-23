#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 1e6 + 5;

vector<int> adj[MAXN];
bool visited[MAXN];

int n, m;
queue<int> q;

void bfs(int v) {
	q.push(v);
	visited[v] = true;
	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (auto u : adj[v]) {
			if (visited[u]) continue;
			visited[u] = true;
			q.push(u);
		}
	}
}

int ccomponents() {
	int counter = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			counter++;
			bfs(i);
		}
	}
	return counter;
}

int main() {
	cin >> n >> m;

	int i, u, v;
	for (i = 0; i < m; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	cout << ccomponents() << endl;
	return 0;
}
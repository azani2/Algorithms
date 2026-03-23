#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
vector <int> adj[1005];
bool visited[MAXN];

int n, m;


void dfs(int u) {
	visited[u] = true;
	cout << u << " ";
	for (auto v : adj[u]) {
		if (!visited[v]) dfs(v);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int u ,v;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 0; i < n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	dfs(0);
}
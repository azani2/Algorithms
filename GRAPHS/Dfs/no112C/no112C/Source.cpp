#include <iostream>
#include <vector>
using namespace std;

#define MAXN 10005

int n, m, x, y;
int comps[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int comp) {
	comps[v] = comp;
	for (int u : adj[v]) {
		if (!comps[u]) dfs(u, comp);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	int cur_comp = 1;
	for (int i = 1; i <= n; i++) {
		if (!comps[i]) dfs(i, cur_comp++);
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> x >> y;
		cout << (comps[x] == comps[y]);
	}
	cout << endl;
	return 0;
}


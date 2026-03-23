#include <iostream>
#include <vector>
using namespace std;

#define MAX 1024

int n, m, k, a, b, c, ans;

bool visited[MAX];

vector<pair<int, int>> adj[MAX];

void dfs(int x) {
	visited[x] = true;
	for (auto y : adj[x]) {
		if (visited[y.first]) continue;
		if (y.second < k) continue;
		dfs(y.first);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	cin >> k;

	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			ans++;
			dfs(i);
		}
	}

	cout << ans - 1 << endl;
	return 0;
}
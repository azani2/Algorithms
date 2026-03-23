#include <iostream>
#include <vector>
using namespace std;
const int  MAXN = 1e5 + 5;

int n, m;
vector<pair<int, bool>> adj[MAXN];
bool visited[MAXN];

void dfs(int x, int col, int colCnt[]) {
	visited[x] = true;
	colCnt[col]++;

	for (auto e : adj[x]) {
		if (visited[e.first]) continue;
		dfs(e.first, col ^ e.second, colCnt);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; //ako e global ne minavat testovete
		char c;   //ako e global ne minavat testovete

		cin >> x >> c >> y;

		if (c == 'h') {
			adj[x].push_back({ y, 0 });
			adj[y].push_back({ x, 0 });
		}
		else {
			adj[x].push_back({ y, 1 });
			adj[y].push_back({ x, 1 });
		}
	}

	int ans = 0; //ako e global ne minavat testovete

	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		int colCnt[2] = { 0, 0 };
		dfs(i, 0, colCnt);
		ans += max(colCnt[0], colCnt[1]);
	}

	cout << ans << endl;
}
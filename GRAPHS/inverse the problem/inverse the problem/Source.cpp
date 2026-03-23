#include <iostream>
#include <queue>
#include <climits>
#include <vector>
using namespace std;
#define MAX 2005

struct edge {
	long w, a, b;
	bool operator<(const edge& other) const {
		return w < other.w;
	}
};

long n, m[MAX][MAX], w, par[MAX], d[MAX], edgesCnt, dist[MAX][MAX];
priority_queue<edge> edges;
vector<pair<int, int>> t[MAX];
bool used[MAX];
bool failMatrix;

int find(int a)
{
	if (par[a] == -1) return a;
	return par[a] = find(par[a]);
}

void uni(int a, int b)
{
	a = find(a);
	b = find(b);
	if (d[a] > d[b])
	{
		par[b] = a;
	}
	else
	{
		par[a] = b;
		if (d[a] == d[b]) d[b]++;
	}
}

void Kruskal() {
	std::fill(par, par + n + 2, -1);
	for (int i = 0; i < edges.size(); i++) {
		int x = edges.top().a;
		int y = edges.top().b;
		w = -edges.top().w;
		edges.pop();

		if (find(x) != find(y)) {
			edgesCnt++;
			uni(x, y);
			t[x].push_back({ y, w });
			t[y].push_back({ x, w });
		}
	}
}

void dfs(int s, int curr, int acc) {
	used[curr] = 1;
	dist[s][curr] = acc;
	for (auto p : t[curr]) {
		if (used[p.first]) continue;
		dfs(s, p.first, acc + p.second);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> w;
			m[i][j] = w;
			if (w == 0) continue;
			if (i == j && w != 0) failMatrix = 1;
			if (i < j) edges.push({ -w, i, j });
		}
	}

	if (failMatrix) {
		cout << "NO" << endl;
		return 0;
	}
	
	Kruskal();

	if (edgesCnt != n - 1) {
		cout << "NO" << endl;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		std::fill(used, used + n + 1, 0);
		dfs(i, i, 0);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dist[i][j] != m[i][j]) {
				cout << "NO\n";
				return 0;
			}
		}
	}

	cout << "YES\n";
	return 0;
}
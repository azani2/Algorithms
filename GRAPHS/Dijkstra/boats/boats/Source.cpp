#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
#define MAX 1005

int n, m, k, maxWidth[MAX], a, b, w;
bool used[MAX];
vector<pair<int, int>> g[MAX];
priority_queue<pair<int, int>> ans;
priority_queue<pair<int, pair<int, int>>> tasks;

void dijkstra(int x) {
	priority_queue<pair <int, int>> pq;
	fill(maxWidth, maxWidth + n + 1, -1);
	fill(used, used + n + 1, 0);
	maxWidth[x] = INT_MAX;
	pq.push({ maxWidth[x], x });
	while (!pq.empty()) {
		int y = pq.top().second;
		pq.pop();
		if (used[y]) continue;
		used[y] = 1;
		for (auto p : g[y]) {
			if (p.first > maxWidth[p.second]) {
				if (p.first <= maxWidth[y]) 
					maxWidth[p.second] = p.first;
				else 
					maxWidth[p.second] = maxWidth[y];
				pq.push({ maxWidth[p.second], p.second });
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
		cin >> a >> b >> w;
		g[a].push_back({ w, b });
		g[b].push_back({ w, a });
	}
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		tasks.push({a, {i, b}});
	}

	pair<int, pair<int, int>> prev = tasks.top();
	tasks.pop();
	dijkstra(prev.first);
	ans.push({-prev.second.first, maxWidth[prev.second.second]});

	while (!tasks.empty()) {
		pair<int, pair<int, int>> x = tasks.top();
		tasks.pop();
		if (prev.first != x.first) {
			dijkstra(x.first);
			prev = x;
		}
		ans.push({ -x.second.first, maxWidth[x.second.second] });
	}
	while (!ans.empty()) {
		cout << ans.top().second << endl;
		ans.pop();
	}

	return 0;
}
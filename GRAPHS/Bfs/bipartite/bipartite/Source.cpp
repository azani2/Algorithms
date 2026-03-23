#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visited[105];
int level[105];
int n, m;

bool bfs(vector<vector<int>>& g, int x) {
    queue<int> q;
    q.push(x);

    while (!q.empty()) {
        x = q.front();
        visited[x] = true;
        q.pop();
        for (auto y : g[x]) {
            if (visited[y]) {
                if (level[y] == level[x]) return false;
                continue;
            }
            visited[y] = true;
            level[y] = level[x] + 1;
            q.push(y);
        }
    }
}

bool isBipartite(vector<vector<int>>& graph) {

    for (int i = 0; i < graph.size(); i++) {
        if (visited[i]) continue;
        visited[i] = true;
        level[i] = 0;
        if (!bfs(graph, i)) return false;
    }
    return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int u, v;
	cin >> n >> m;
    vector<vector<int>> g;
    for (int i = 0; i < n; i++) {
        g.push_back(vector<int>());
    }

	for (int i = 0; i < m; i++) {

		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int i = 0; i < n; i++) {
		sort(g[i].begin(), g[i].end());
	}
    cout << isBipartite(g);
	return 0;
}
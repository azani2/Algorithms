#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define MAX 155

using namespace std;
int n, m, s, a, b, v, l;
struct edge {
	int node;
	int speed;
	int length;
};
vector<edge> adj[MAX];

pair<int, int> par[MAX]; // par, speed
long double d[MAX];
bool visited[MAX];
priority_queue<pair<long double, int>> pq; // time (dist), nod

void dijkstra() {
	fill(d, d + n + 2, INT_MAX / 2);
	d[0] = 0;
	par[0] = { -1, 70 };
	pq.push({ -d[0], 0 });

	while (!pq.empty()) {
		int node = pq.top().second;
		pq.pop();

		if (visited[node]) {
			continue;
		}
		visited[node] = 1;

		for (auto p : adj[node]) {
			int v = p.node;
			int sp = p.speed > 0 ? p.speed : par[node].second;
			int len = p.length;
			long double t = (long double)len / (long double)sp;
			if (d[v] > d[node] + t) {
				d[v] = d[node] + t;
				par[v] = { node, sp };
				pq.push({ -d[v], v });
			}
		}
		
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> v >> l;
		adj[a].push_back({ b,v,l });
	}
	
	dijkstra();
	vector<int> path;
	int x = s;
	path.push_back(x);
	while (par[x].first != -1) {
		x = par[x].first;
		path.push_back(x);
	}
	
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] << " ";
	}

	cout << endl;
 	return 0;
}

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;

#define MAXN 1024

int n, k, f, m, x, y, cnt, v, fam[MAXN];
string a, b, names[MAXN];
set<pair<int, int>> edges;

map<string, int> index;
bool famous[MAXN];
vector<int> adj[MAXN];
queue<int> q;
vector<string> ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k >> f >> m;
	for (int i = 0; i < f; i++) {
		cin >> a;
		if (!index.count(a)) {
			names[cnt] = a;
			index[a] = cnt++;
		}
		x = index[a];
		q.push(x);
		famous[x] = true;
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (!index.count(a)) {
			names[cnt] = a;
			index[a] = cnt++;
		}
		if (!index.count(b)) {
			names[cnt] = b;
			index[b] = cnt++;
		}
		x = index[a];
		y = index[b];

		if (x > y) swap(x, y);
		if (!edges.count({ x, y })) {
			adj[x].push_back(y);
			adj[y].push_back(x);
			edges.insert({ x, y });
		}
	}

	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (int u : adj[v]) {
			fam[u]++;
			if (fam[u] == k && !famous[u]) {
				q.push(u);
				famous[u] = 1;
			}
		}
	}

	for (int i = 0; i < cnt; i++) {
		if (famous[i]) ans.push_back(names[i]);
	}

	sort(ans.begin(), ans.end());
	for (string name : ans) {
		cout << name << " ";
	}

	cout << endl;
	return 0;
}


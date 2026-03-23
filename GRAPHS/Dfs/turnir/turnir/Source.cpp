#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

#define MAXN 100005

int n;
bool visited[MAXN];
vector<int> adj[MAXN];
set<pair<int, int>> edges;
vector<int> ans;

void dfs(int v, vector<int>& comp) {
	visited[v] = true;
	comp.push_back(v);

	for (int u : adj[v]) {
		if (!visited[u]) dfs(u, comp);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);

		edges.insert({ x, y });
		edges.insert({ y, x });
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;

		vector<int> comp;
		dfs(i, comp);

		if (comp.size() <= 2) {
			ans.push_back(i);
		} 
		else {
			if (edges.count(make_pair(comp.front(), comp.back()))) { // samo s make pair raboti
				vector<int> opt1;
				for (int j = 0; j < comp.size() - 1; j += 2) 
					opt1.push_back(comp[j]); 

				vector<int> opt2;
				reverse(comp.begin() + 1, comp.end());
				for (int j = 0; j < comp.size() - 1; j += 2)
					opt2.push_back(comp[j]);

				sort(opt1.begin(), opt1.end());
				sort(opt2.begin(), opt2.end());

				if (opt1 > opt2)
					for (int v : opt2) ans.push_back(v);
				else
					for (int v : opt1) ans.push_back(v);

			}
			else {
				for (int j = 0; j < comp.size(); j += 2) 
					ans.push_back(comp[j]);
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;

	cout << ans[0];
	for (int i = 1; i < ans.size(); i++)
		cout << " " << ans[i];
	
	cout << endl;
}
//exceeeds time limit
//check notes


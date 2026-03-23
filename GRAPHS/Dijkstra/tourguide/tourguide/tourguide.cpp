#include <vector>
#include <queue>
#include <iostream>
#include <climits>

using namespace std;
#define MAX 100024

vector<pair<int, int> > gr[MAX];

bool used[MAX];

int d[MAX];

priority_queue<pair<int, int> > pq;

int n, m, k, q, a, b, c, start;

void dijkstra(int from) {
	fill(d, d + n + 2, INT_MAX);
	d[from] = 0;
	pq.push({ d[from],from });

	while (!pq.empty()) {
		int x = pq.top().second;
		pq.pop();
		if (used[x]) continue;
		used[x] = 1;

		for (auto p : gr[x]) {
			int y = p.first;
			int t = p.second;
			if (d[y] > d[x] + t) {
				d[y] = d[x] + t;
				pq.push({ -d[y], y });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		gr[a].push_back({ b, c });
		gr[b].push_back({ a, c });
	}

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> a;
		gr[n].push_back({ a, 0 });
	}

	dijkstra(n);
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> a;
		cout << d[a] << endl;
	}
	return 0;
}

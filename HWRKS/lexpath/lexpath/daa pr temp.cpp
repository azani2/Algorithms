#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define MAXN 300005

using namespace std;

long long n, m, x, y;
char c;
bool visited[MAXN];
vector<pair <long long, char>> adj[MAXN];

struct dist {
	string p;

	bool operator<(const dist& other) const {
		return p.size() > other.p.size() ||
			p.size() == other.p.size() && p > other.p;
	}


};

dist d[MAXN];
priority_queue<pair<dist, long long>> pq;

void dijkstra(long long s) {
	string inf;
	inf.append(MAXN, 'z');
	for (int i = 1; i <= n; i++) d[i] = { inf };
 
	d[s] = { "" };
	pq.push({ d[s], s });

	while (!pq.empty()) {
		long long u = pq.top().second;
		pq.pop();

		if (visited[u]) continue;
		visited[u] = 1;

		for (auto p : adj[u]) {
			long long v = p.first;
			char newChar = p.second;

			string newDist = "";
			newDist.append(d[u].p);
			newDist.append(1, newChar);

			if (d[v] < dist{newDist} ) {
				d[v].p.clear();
				d[v].p.append(newDist);
				pq.push({ d[v], v });
			}
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> c;
		adj[x].push_back({ y,c });
		adj[y].push_back({ x,c });
	}

	dijkstra(1);

	//for (int i = 1; i <= n; i++) {
	//	cout << i << " : " << d[i].p << endl;
	//}
	cout << d[n].p << endl;

	return 0;
}

/*
9 13
1 2 a
1 3 a
2 4 c
3 4 b
3 5 b
4 6 a
4 7 a
5 6 b
7 8 b
6 8 b
1 6 a
2 9 b
4 8 c


9 13
1 2 a
1 3 a
2 4 a
3 4 a
3 5 a
4 6 a
4 7 a
5 6 a
7 8 a
6 8 a
1 6 a
2 9 a
4 8 a

6 6
1 2 a
1 3 b
2 4 c
3 4 d
4 5 e
5 6 f
4 6 c
*/
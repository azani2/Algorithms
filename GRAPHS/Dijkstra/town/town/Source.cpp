#include <iostream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;
#define MAX 2000024

vector<pair<int, int>> gr[MAX];
bool used[MAX];
int d[MAX], start, last, n, a, b, c, y, w;

void bfs(int node) {
	deque<int> q;
	q.push_back(node);
	fill(d, d + n + 1, INT_MAX / 2);
	d[node] = 0;

	while (!q.empty()) {
		node = q.front();
		q.pop_front();
		for (auto p : gr[node]) {
			y = p.first;
			w = p.second;

			if (d[y] > d[node] + w) {
				d[y] = d[node] + w;
				if (w == 0) q.push_front(y);
				else q.push_back(y);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> start >> last;

	while (cin >> a >> b)
	{
		gr[a].push_back({ b, 0 });
		gr[b].push_back({ a, 1 });
	}

	bfs(start);

	if (d[last] == INT_MAX / 2) cout << "X" << endl;
	else cout << d[last] << endl;
	return 0;
}
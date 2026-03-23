#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
#define MAX 1000000

using InvertedPriorityQueue = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
int n;
int d[MAX + 5];

vector<pair<int, int>> g[MAX + 5];

void dijkstra() {
	for (int x = 1; x <= MAX; x++)  d[x] = INT_MAX;
	
	InvertedPriorityQueue pq;
	pq.emplace(0, 1);
	d[1] = 0;

	while(!pq.empty()) {
		int x = pq.top().second;
		int dist = pq.top().first;
		pq.pop();

		if (d[x] != dist) continue;
		for (auto& p : g[x]) {
			if (d[p.first] > d[x] + p.second) {
				d[p.first] = d[x] + p.second;
				pq.emplace(d[p.first], p.first);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int U, D, I, J, L;
	//n floors
	//u lv per floor for staris up
	//d -//- stairt down
	//i for entering lift
	//j for leaving lift
	//l lifts total

	cin >> n >> U >> D >> I >> J >> L;
	for (int i = 2; i <= MAX; i++) {
		g[i - 1].emplace_back(i, U);
		g[i].emplace_back(i - 1, D);
	}

	for (int i = 0; i < L; i++) { // L lifts
		int k;
		cin >> k;
		//k floors reachable by current lift i
		//all of these floors have edges to each other with price I + J
		vector<int> floors(k);
		for (int j = 0; j < k; j++) {
			cin >> floors[j];
			//add new reachable floor to all j floors already added to this lift
			for (int p = 0; p < j; p++) {
				g[floors[p]].emplace_back(floors[j], I + J);
				g[floors[j]].emplace_back(floors[p], I + J);
			}
		}
	}
	dijkstra();
	cout << d[n] << endl;
}
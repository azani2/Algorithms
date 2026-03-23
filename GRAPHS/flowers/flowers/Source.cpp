#include <iostream>
#include <vector>
#include <queue>
#define MAX 20010
using namespace std;

int k, rowSz, f, finSz, ok, n, maxDelay;
bool finished[MAX];
priority_queue<int> pq;
int toBeBefore[MAX];
bool taken[MAX];
vector<int> g[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> k;

	for (int i = 0; i < k; i++) {
		vector<int> row;
		cin >> rowSz;
		for (int j = 0; j < rowSz; j++) {
			cin >> f;
			row.push_back(f);

			if (!taken[f]) n++;
			taken[f] = 1;

			if (j > 0) {
				toBeBefore[f] = max(toBeBefore[row[j - 1]] + 1, toBeBefore[f]);
				g[row[j - 1]].push_back(f);
			}
		}
	}
	for (size_t i = 0; i < n  + 10; i++) 
		if(taken[i]) cout << i << " is after " << toBeBefore[i] << " other kitki" << endl;
	
	
	for (int i = 1; i <= n+10; i++) {
		if (taken[i] && toBeBefore[i] == 0) { pq.push(i); cout << i << endl; }
	}

	while (!pq.empty()) {
		int fl = pq.top();
		finished[fl] = 1;
		cout << "finished " << fl << endl;
		pq.pop();
		finSz++;
		for (int flo : g[fl]) {
			if (finished[flo]) {
				cout << 0 << endl;
				return 0;
			}
			toBeBefore[flo]--;
			if (toBeBefore[flo] == 0) {
				pq.push(flo);
			}
		}
	}
	cout << n << " " << finSz << endl;
	if (finSz != n) cout << 0<<endl;
	else cout << 1 << endl;

	return 0;

}

/*
2
3 1 2 3
4 1 3 5 6

*/
#include <iomanip>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 100005

int n, k, w, p[MAXN], c[MAXN], cnt, j;

priority_queue<int> pq;
pair <int, int> arr[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k >> w;
	for (int i = 0; i < n; i++) cin >> p[i];
	for (int i = 0; i < n; i++) cin >> c[i];

	for (int i = 0; i < n; i++) 
		arr[i] = {p[i], c[i]};
	
	sort(arr, arr + n,
		[](pair <int, int> a, pair <int, int> b)
		{
			if (a.second != b.second) return a.second < b.second;
			else return a.first < b.first;
		});

	for (int i = 0; i < n; i++) {
		cout << "{" << arr[i].first << ", " << arr[i].second << "} ";
	}
	cout << endl;

	while (cnt < k) {
		while (j < n && arr[j].second <= w) {
			pq.push(arr[j].first);
			j++;
		}

		if (pq.empty()) break;

		w += pq.top();
		pq.pop();
		cnt++;
	}

	cout << w << endl;
	return 0;
}
/*
6 3 0
4 3 3 2	 11 2
10 3 2 2 0 0
------------------
.: 18 = 11 + 4 + 3

6 3 0
4 3 3 2	 5 2
10 3 2 2 0 0
-----------------
.: 11 = 5 + 3 + 3
*/
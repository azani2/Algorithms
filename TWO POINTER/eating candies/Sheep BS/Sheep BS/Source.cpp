#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 200005

int t, n, maxCand, w[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> t;

	for (int i = 0; i < t; i++) {
		maxCand = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> w[i];
	
		for (int i = 2; i <= n; i++)
			w[i] += w[i - 1];

		int x = n - 1;
		while (w[x] >= w[n] - w[x])
			x--;

		for (int i = n; i > x + 1; i--)
			w[i] -= w[i - 1];
		for (int i = n - 1; i > x + 1; i--)
			w[i] += w[i + 1];

		int a = 1, b = n;
		while (a != b) {
			if (w[a] < w[b]) a++;
			else if (w[b] < w[a]) b--;
			else {
				maxCand = a + n - b + 1;
				a++;
			}
		}

		cout << maxCand << endl;
	}

	return 0;
}
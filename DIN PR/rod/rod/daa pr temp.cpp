#include <iostream>
#include <climits>
#define MAX 1002

using namespace std;

int n;
int a[MAX];
int d[MAX][MAX];

long long calc(int s, int e) {
	if (s == e - 1) return 0;
	if (d[s][e]) return d[s][e];

	int currW = 0;
	for (int i = s + 1; i <= e; i++) {
		currW += a[i];
	}

	int incomingW = INT_MAX;
	for (int i = s + 1; i < e; i++) {
		int t = calc(s, i) + calc(i, e);
		if (incomingW > t) {
			incomingW = t;
		}
	}
	return d[s][e] = currW + incomingW;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	cout << calc(0, n) << endl;

	return 0;
}

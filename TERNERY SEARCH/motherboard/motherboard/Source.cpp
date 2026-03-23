#include <math.h>
#include <iostream>
using namespace std;

#define MAXN 105

long long ans = 1000000000, n, lo = 1000000000, hi = -1000000000, m1, m2, x[MAXN], y[MAXN];

long long maxDist(long long Y) {
	long long maxD = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			long long d = abs(y[i] - Y) + abs(x[i] - x[j]) + abs(y[j] - Y);
			maxD = max(d, maxD);
		}
	}
	return maxD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
		lo = min(lo, y[i]);
		hi = max(hi, y[i]);
	}

	while (lo < hi) {
		m1 = lo + (hi - lo) / 3;
		m2 = lo + 2 * (hi - lo) / 3;

		long long d1 = maxDist(m1);
		long long d2 = maxDist(m2);
		if (d1 < d2) {
			hi = m2 - 1;
			ans = min(ans, d1);
		}
		else {
			lo = m1 + 1;
			ans = min(ans, d2);
		}
	}

	cout << ans << endl;
	return 0;
}
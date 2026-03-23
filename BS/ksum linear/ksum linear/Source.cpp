#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 200005

long long n, k;
long long a[MAXN], b[MAXN];

long long f(long long x) {
	long long ans = 0;
	int j = n;
	for (int i = 1; i <= n; i++) {
		while (j >= 1 && a[i] + b[j] > x) j--;
		ans += j;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];

	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);

	long long l = a[1] + b[1], r = a[n] + b[n];
	while (l <= r) {
		long long mid = (l + r) / 2;

		if (f(mid) < k) l = mid + 1;
		else r = mid - 1;
	}

	cout << l << endl;
	return 0;
}
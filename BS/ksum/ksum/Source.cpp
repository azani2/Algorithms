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
		int l = 0, r = j;
		while (l + 2 <= r) {
			int mid = (l + r) / 2;
			if (b[mid] > x - a[i]) r = mid - 1;
			else l = mid;
		}
		while (l <=n && b[l] <= x - a[i]) l++;
		j = l-1;
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

	sort(a + 1, a + n +1);
	sort(b+1, b + n +1);

	long long l = 0, r = a[n] + b[n];
	while (l <= r) {
		long long mid = (l + r) / 2;

		if (f(mid) < k) l = mid + 1;
		else r = mid - 1;
	}

	cout << l << endl;
	return 0;
}
/*
minava s 34 tochki
lineinoto f e dostatuchno dobro

4 4
1 3 5 7
2 4 6 8
-------
.: 7

4 7
1 3 5 7
2 4 6 8
-------
.: 9

4 10
1 3 5 7
2 4 6 8
-------
.: 9

4 16
1 3 5 7
2 4 6 8
-------
.: 15

4 5
1 2 11 13
7 9 20 100
----------
.: 18

4 7
1 2 11 13
7 9 20 100
----------
.: 20

4 12
1 2 11 13
7 9 20 100
----------
.: 33

4 14
5 1 8 1
3 2 7 4
-------
.:12
*/
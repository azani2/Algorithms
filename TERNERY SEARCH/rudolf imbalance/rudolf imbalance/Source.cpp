#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

#define MAX 200005

long n, m, k, t, maxImb, second, ans, lo, hi;
long a[MAX], d[MAX], f[MAX]; 
// a is sorted by input
vector<long> res;

long calc(long x) { // moje i da namerim optimalno j s ternery...
	long di = d[x];
	long imb = maxImb;
	long j = 0;
	long fmin = a[lo] - di;
	long fmax = a[hi] - di;
	long l = 0, r = k - 1;
	while (l <= r) { // find where available fjs start and write it to j
		long mid = l + (r - l) / 2;
		if (f[mid] <  fmin) {
			l = mid + 1;
			j = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	//all available js are in f[j...M-1] where f[M] > fmax or M = k 
	// try all of them 
	while (j < k && f[j] <= fmax) {
		long maxDist = max(abs(di + f[j] - a[lo]), abs(di + f[j] - a[hi]));
		imb = min(imb, maxDist);
		imb = max(imb, second);
		j++;
	}
	return imb;
}

void solve() {
	sort(d, d + m);
	sort(f, f + k);

	ans = maxImb;
	long l = 0, r = m - 1;
	while (l <= r) {
		long m1 = l + (r - l) / 3;
		long m2 = r- (r - l) / 3;
		long max1 = calc(m1);
		long max2 = calc(m2);
		ans = min(ans, min(max1, max2));
		if (max1 < max2) {
			r = m2 - 1;
		}
		else {
			l = m1 + 1;
		}
	}

	res.push_back(ans);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m >> k;
		maxImb = 0;
		second = 0;
		for (int j = 0; j < n; j++) {
			cin >> a[j];
			if (j) {
				if (maxImb < a[j] - a[j - 1]) {
					second = maxImb;
					maxImb = a[j] - a[j - 1];
					lo = j - 1;
					hi = j;
				}
			}
		}
		for (int j = 0; j < m; j++) cin >> d[j];
		for (int j = 0; j < k; j++) cin >> f[j];solve();
	}

	for (int i = 0; i < t; i++) cout << res[i] << endl;
	return 0;
}

/*

1
5 5 5
5 10 15 20 26
11 14 16 13 8
16 4 5 3 1
---------------------------
.:5

1
7 6 5
1 4 7 10 18 21 22
2 2 3 4 5 7
2 3 6 8 9
---------------------------
.: 4

7
5 5 5
5 10 15 20 26
11 14 16 13 8
16 4 5 3 1
7 6 5
1 4 7 10 18 21 22
2 3 5 7 4 2
6 8 9 3 2
7 6 5
1 4 7 10 18 21 22
2 3 5 7 4 2
6 8 13 3 2
5 6 3
2 10 13 20 25
11 6 10 16 14 5
6 17 15
4 2 2
11 12 14 15
19 14
10 6
8 4 2
3 10 16 18 21 22 29 30
9 13 16 15
4 2
2 4 7
4 21
4 15 14 5
20 1 15 1 12 5 11
---------------------------
.:
5
4
5
8
2
7
11

*/
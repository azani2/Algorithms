#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 100005

long s, maxK, minPr;
long n, l, r, mid;
pair<long, int> a[MAXN];

long calc() {
	sort(a, a + n,
		[](pair<long, int> x, pair<long, int> y)
		{
			return (x.first + x.second * mid) < 
				   (y.first + y.second * mid);
		});
	long sum = 0;
	for (int i = 1; i <= mid; i++)
		sum += a[i].first + a[i].second * mid;
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}

	l = 0;
	r = n;
	while (l <= r) {
		mid = (l + r) / 2;
		long p = calc();
		if (p > s) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
			if (mid > maxK) {
				maxK = mid;
				minPr = p;
			}
		}
	}

	cout <<maxK << " " << minPr << endl;
	return 0;
}
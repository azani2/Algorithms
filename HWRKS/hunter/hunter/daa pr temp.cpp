#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000005

using namespace std;

long long n, l, d, a[MAX], x, y;


bool f(int pos) {
	vector<long long> v;
	for (int i = 1; i <= pos; i++) {
		v.push_back(a[i]);
	}
	sort(v.begin(), v.end());
	int s = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] - s <= d)
			s = v[i];
		else 
			return false;
	}
	return l-s <= d;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> l >> d;

	cin >> a[1] >> x >> y;
	for (int i = 2; i <= n; i++) {
		a[i] = (a[i - 1] * x + y) % (l + 1);
	}

	long long ans = -1;
	long long l = 1; long long r = n - 1;
	while (l <= r) {
		long long mid = l + (r - l) / 2;
		if (f(mid)) {
			r = mid - 1;
			ans = mid;
		}
		else {
			l = mid + 1;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}

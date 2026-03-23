#include <iostream>
using namespace std;

long long n, f, l = 1, r, mid, ans;

long long sumBefore(long long m) {
	return f * (m - 1) + (m - 1) * (m - 2) / 2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> f;

	r = 2e9;

	while (l < r) {
		mid = l + (r - l) / 2;
		if (sumBefore(mid) < n) l = mid + 1;
		else {
			ans = mid;
			r = mid;
		}
	}

	cout << l - 1 << endl;
}
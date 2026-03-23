#include <iostream>
#include <climits>
#define MAX 100010
using namespace std;

int a[MAX], d[MAX], n;

int calc(int idx) {
	if (idx >= n) return 0;
	if (d[idx] != INT_MIN) return d[idx];

	int ans = a[idx];
	ans += max(calc(idx + 1), a[idx+2] + calc(idx + 3));
	return d[idx] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	fill(d, d + n + 2, INT_MIN);
	a[n] = 0;
	d[n] = 0;
	cout << calc(1) << endl;
	for (int i = 1; i <= n; i++) cout << d[i] << " ";


	return 0;
}//wa

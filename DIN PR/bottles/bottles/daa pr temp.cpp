#include <iostream>
#define MAX 101000

using namespace std;

int n, a[MAX], d[MAX];

long long calc(int x) {
	if (x > n) return 0;
	if (x >= n - 1) return a[x];
	if (d[x]) return d[x];

	long long ans = max(a[x] + calc(x + 2), a[x] + calc(x + 3));
	return d[x] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <=n; i++) cin >> a[i];

	cout << max(calc(1), calc(2)) << endl;

	return 0;
}

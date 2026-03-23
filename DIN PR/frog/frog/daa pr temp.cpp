#include <iostream>
#include <climits>
using namespace std;
#define MAXN 10010
int n;
int h[MAXN], dp[MAXN];

long long calc(int x) {
	if (x > n) return INT_MAX;
	if (x == n) return 0;
	if (dp[x] != -1) return dp[x];

	return dp[x] = min(calc(x + 1) + abs(h[x] - h[x + 1]),
		calc(x + 2) + abs(h[x] - h[x + 2]));
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i];

	fill(dp, dp + n + 2, -1);

	cout << calc(1) << endl;
	return 0;
}

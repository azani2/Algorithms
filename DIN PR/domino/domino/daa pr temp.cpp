#include <iostream>
#define MOD 1000000007
#define MAXN 2020
using namespace std;
long long dp[MAXN];

long long calc(long long x) {
	if (x <= 0) return 0;
	if (x == 1) return 1;
	if (x == 2) return 2;
	if (dp[x] != -1) return dp[x];
	return dp[x] = (calc(x - 1) + calc(x - 2)) % MOD;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n;

	cin >> n;
	fill(dp, dp + n + 2, -1);
	cout << calc(n) << endl;

	return 0;
}

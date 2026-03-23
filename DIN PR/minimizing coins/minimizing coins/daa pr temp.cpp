#include <iostream>
#include <climits>
#define MAXN 110

using namespace std;
int n;
int dp[MAXN], c[MAXN];

int calc( int s) {
	if (s < 0) return INT_MAX;
	if (s == 0) return 0;
	if (dp[s]) return dp[s];

	int ans = INT_MAX;
	for (int i = 0; i < n; i++) {
		ans = min(ans, 1 + calc(s - c[i]));
	}
	return  dp[s] = ans;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> c[i];
	int ans = calc(s);
	if (ans < INT_MAX) cout << ans << endl;
	else cout << -1 << endl;
	return 0;
}

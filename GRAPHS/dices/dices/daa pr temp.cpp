#include <iostream>

using namespace std;
#define MOD 1000000007
#define MAX 6020
#define MAXN 1024

long long c[MAXN][MAX];
bool calculated[MAXN][MAX];

long long dices(int n, int s) {
	if (s < 0) return 0;
	if (s == 0) return (n == 0);
	if (n == 0) return 0;

	if (calculated[n][s]) return c[n][s];
	calculated[n][s] = 1;
	long long ans = 0;
	for (int i = 1; i <= 6; i++) ans += dices(n - 1, s - i);
	return c[n][s] = ans % MOD;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, s;
	cin >> n >> s;

	for (int i = 0; i < MAXN; i++) {
		fill(c[i], c[i] + MAX, -1);
	}
	cout << dices(n, s) << endl;
	return 0;
}

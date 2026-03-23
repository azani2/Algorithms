#include <iostream>

#define MAX 10005
using namespace std;
const long long MOD = 1e9 + 7;

long long d[MAX][MAX];
int n, m, a, b, k;

long long calc(int x, int y, int t) {
	if (t < 0 || x> n || y > m) return 0;
	if (x == n && y == m && t > 0) return 0;
	else if (x == n && y == m)  return 1; 
	if (d[x][y]) return d[x][y];

	for (int x1 = x; x1 <= n && x1 <= x + a; x1++) {
		for (int y1 = y; y1 <= m && y1 <= y + b; y1++) {
			if (x1 == x && y1 == y) continue;
			d[x][y] += calc(x1, y1, t - 1);
		}
	}
	return d[x][y] %= MOD;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> a >> b >> k;

	cout << calc(0, 0, k) << endl;


	return 0;
}

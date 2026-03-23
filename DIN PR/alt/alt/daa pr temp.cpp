#include <iostream>
#define MAXN 52
#define MAXK 52
using namespace std;

int k, m, n;
long long d[2][MAXK];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	cin >> k >> m >> n;

	for (int i = 1; i < m; i++) d[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < m; j++) {
			int row = i % 2;
			d[row][j] = 0;

			if (j - k > 0) d[row][j] += d[1 - row][j - k];
			if (j + k < m) d[row][j] += d[1 - row][j + k];
		}
	}

	long long ans = 0;

	for (int i = 1; i < m; i++) ans += d[n % 2][i];
	cout << ans << endl;
	
	return 0;
}

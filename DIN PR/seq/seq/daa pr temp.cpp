#include <iostream>
#define MAXK 55
#define MAXN 55
using namespace std;

int k, n;
long long d[MAXK][MAXN];

long long calc(int x, int y) {
	if (y == 0) return 1;
	if (x == 0)return 0;
	if (d[x][y] != -1) return d[x][y];

	return d[x][y] = calc(x - 1, y - 1) + calc(x - 1, y);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> k >> n;
	for (int i = 0; i <= n; i++) d[i][0] = 1;

	for (int i = 0; i <= k; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			d[i][j] = -1;
		}
	}

	cout << calc(k, n) <<endl;
	return 0;
}
 
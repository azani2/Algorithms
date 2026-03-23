#include <iostream>
using namespace std;
int n, m, d[128][128];

int calc(int x, int y) {
	if (x == n || y == m) return 1;
	if (d[x][y]) return d[x][y];

	return d[x][y] = calc(x + 1, y) + calc(x, y + 1);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	cout << calc(1, 1) << endl;
	return 0;
}

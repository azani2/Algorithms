#include <iostream>
#include <cstring>
#define MAX 2048
using namespace std;

long long d[MAX][MAX];
string a, b;
int n, m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> a >> b;
	n = a.size();
	m = b.size();

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= m; j++) {

			if (a[i - 1] == b[j - 1]) {
				d[i][j] = d[i - 1][j - 1] + 1;
			}
			else {
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
			}
		}
	}
	cout << d[n][m] << endl;

	return 0;
}

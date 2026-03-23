#include <iostream>
#define MAX 10010

using namespace std;

int n, a[MAX], d[MAX], ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	fill(d, d + n + 2, 1);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1 + i; j <= n; j++)
		{
			if (a[i] < a[j])
				d[j] = max(d[j], d[i] + 1);
		}
		ans = max(ans, d[i]);
	}
	cout << ans << endl;
	return 0;
}

#include <iostream>
#define MAX 10100
using namespace std;

int n, a[MAX], b[MAX], c[MAX], d[MAX], ans;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> c[i] >> a[i] >> b[i];
		d[i] = c[i];

		for (int j = 1; j < i; j++)
		{
			if (a[i] <= a[j] && b[i] <= b[j] || 
				b[i] <= a[j] && a[i] <= b[j])
			{
				d[i] = max(d[i], d[j] + c[i]);
			}
		}
		ans = max(ans, d[i]);
	}
	cout << ans << endl;
	return 0;
}

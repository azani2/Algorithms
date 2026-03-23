#include <iostream>
#define ll long long

using namespace std;

const ll MOD = 1e9 + 7;
const int MAX = 6e3 + 3;

int d[2][MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, s;

	cin >> n >> s;
	d[0][0] = 1;

	for (int k = 1; k <= n; k++)
	{
		for (int i = 0; i <= s; i++) 
		{
			d[k % 2][i] = 0;
		}
		for (int sum = 0; sum <= s; sum++)
		{
			for (int j = 1; j <= 6; j++)
			{
				if (sum - j >= 0) 
				{
					d[k % 2][sum] = (d[k % 2][sum] + d[(k - 1) % 2][sum - j]) % MOD;
				}
			}
		}
	}

	cout << d[n % 2][s] << endl;
	return 0;
}

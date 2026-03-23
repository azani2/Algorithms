#include <iostream>
#define MAX 105
#define MOD 1000000007

using namespace std;

string s;
long long n, d[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> s;
	n = s.size();

	for (int i = 0; i < n; i++) d[i][i] = 1;

	for (int i = 0; i < n - 1; i++) {
		d[i][i + 1] = 2 + (s[i] == s[i + 1]);
	}

	for (int len = 2; len < n; len++)
	{

		for (int i = 0; i < n - len; i++)
		{
			int j = i + len;

			if (s[i] == s[j]) 
				d[i][j] = (d[i + 1][j] + d[i][j - 1] + 1) % MOD;

			else 
				d[i][j] = ((d[i + 1][j] + d[i][j - 1] - d[i + 1][j - 1]) % MOD + MOD) % MOD;
		}
	}

	cout << d[0][n - 1] << endl;
	return 0;
}

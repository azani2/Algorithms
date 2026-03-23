#include <iostream>
#define MAX 33
using namespace std;

long long d[MAX][MAX]; //length, sum
int p, n, s;
long long ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> p >> n >> s;

	for (int i = 0; i <= n; i++) d[i][0] = 1;
	for (int j = 0; j < p && j < s; j++) d[1][j] = 1;
	for (int j = p; j < s; j++) d[1][j] = 0;

	for (int i = 2; i <= n; i++) 
	{
		for (int j = 1; j < s; j++)
		{
			for (int x = 0; x < p && x <= j; x++)
			{
				d[i][j] += d[i - 1][j - x];
			}
		}
	}

	for (int j = 0; j < s; j++) ans += d[n][j];
	cout << ans << endl;

    
	return 0;
}


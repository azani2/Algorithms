#include <iostream>
using namespace std;
#define MAX 1000100
#define MOD 1000000007
int n;
long long c[MAX];

long long combs(int x) {
	if (x < 0) return 0;
	if (x == 0) return 1;
	if (c[x]) return c[x];
	long long ans = 0;
	for (int i = 1; i <= 6; i++)
	{
		ans += combs(x - i);
	}
	return c[x] = ans % MOD;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	cout << combs(n) << endl;
	return 0;
}
